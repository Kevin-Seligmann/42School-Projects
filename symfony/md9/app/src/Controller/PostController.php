<?php

namespace App\Controller;

use App\Entity\Post;
use App\Form\PostForm;
use DateTime;
use Doctrine\ORM\EntityManagerInterface;
use Exception;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\Routing\Annotation\Route;

class PostController extends AbstractController {
	#[Route('/')]
	public function defaultAction(EntityManagerInterface $entityManager){
		$form = $this->createForm(PostForm::class, null, [
			'attr' => [
				'onsubmit' => "submitPost(event)",
				'action' => $this->generateUrl('submitPost'),
			]
		]);

		try {
			$posts = $entityManager->getRepository(Post::class)->findAll();
		} catch (Exception $e){
			$posts = [];
		}

		$user = $this->getUser();

		return $this->render('index.html.twig', ['user' => $user, 'form' => $form, 'posts' => $posts]);
	}

	#[Route('/submitPost', name: "submitPost")]
	public function submitPost(Request $request, EntityManagerInterface $entityManager){
		$this->denyAccessUnlessGranted('ROLE_USER');

		$post = new Post();
		$form = $this->createForm(PostForm::class, $post);
		$form->handleRequest($request);

		if ($form->isValid()){
			try {
				$entityManager->persist($post);
				$entityManager->flush();
				return new JsonResponse([
					'success' => 'Post added',
					'title' => $post->getTitle(),
					'created' => $post->getCreated()->format("Y-m-d"),
					'id' => $post->getId(),
					]);
			} catch (Exception $e){
				return new JsonResponse(['error' => 'Couldn\'t add the post']);
			}
		} else {
			$errors = [];
            foreach ($form->getErrors(true, true) as $key => $error) {
                $errors[] = $error->getMessage();
            }

            return new JsonResponse(['errors' => $errors]);
		}
	}

	#[Route('/view/{id}', name: "viewAction")]
	public function viewAction(int $id, EntityManagerInterface $entityManager){

		try {
			$post = $entityManager->find(Post::class, $id);
			if ($post)
				return new JsonResponse([
					'title' => $post->getTitle(),
					'created' => $post->getCreated(),
					'id' => $post->getId(),
					'content' => $post->getContent()
				]);
		} catch (Exception $e){
			return new JsonResponse(['error' => 'Couldn\'t get post']);
		}
	}

	#[Route('/delete/{id}', name: "deleteAction")]
	public function deleteAction(int $id, EntityManagerInterface $entityManager){
		$this->denyAccessUnlessGranted('ROLE_USER');

		try {
			$post = $entityManager->find(Post::class, $id);
			if (!$post)
				return new JsonResponse(['error' => 'Couldn\'t get post']);
			$entityManager->remove($post);
			$entityManager->flush();
			return new JsonResponse(['success' => 'Post deleted', 'id' => $id]);
		} catch (Exception $e){
			return new JsonResponse(['error' => 'Couldn\'t delete post']);
		}
	}
}
