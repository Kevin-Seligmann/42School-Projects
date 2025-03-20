<?php

namespace App\Bundle\E03Bundle\Controller;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E03Bundle\Entity\E03Post;
use App\Bundle\E03Bundle\Form\PostForm;
use App\Bundle\E05Bundle\Entity\Vote;
use App\Bundle\E06Bundle\Entity\PostEdit;
use App\Bundle\E07Bundle\Service\UserPrivilegeService;
use DateTime;
use Exception;
use Doctrine\ORM\EntityManagerInterface;
use Psr\Log\LoggerInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;

class PostController extends AbstractController {
	#[Route('/create_post', name: 'ex03_post_form')]
	public function index(Request $request, EntityManagerInterface $entityManager, LoggerInterface $logger)
	{
		$this->denyAccessUnlessGranted('ROLE_USER');

		$post = new E03Post();
		$form = $this->createForm(PostForm::class, $post);
		$form->handleRequest($request);
		if ($form->isSubmitted() && $form->isValid())
		{
			try {
				$user = $this->getUser();
				$post->setAuthor($user);
				$post->setCreated(new DateTime());
				$entityManager->persist($post);
				$entityManager->flush();
				return $this->redirectToRoute('ex03_post', ['id' => $post->getId()]);
			} catch (Exception $e){
				$logger->error($e->getMessage());
				$this->addFlash('error', "Error creating post");
				return $this->redirectToRoute('ex01_homepage');
			}
		}
		return $this->render('@E03Bundle/create_post.html.twig', ['form' => $form]);
    }

	#[Route('/post/{id}', name: 'ex03_post')]
	public function show(int $id, EntityManagerInterface $entityManager, LoggerInterface $logger, UserPrivilegeService $privileges)
	{
		$this->denyAccessUnlessGranted('ROLE_USER');

		try {
			$post = $entityManager->find(E03Post::class, $id);
			if (!$post){
				$this->addFlash('error', "Post not found");
				return $this->redirectToRoute('ex01_homepage');	
			}

			$voteRepository =  $entityManager->getRepository(Vote::class);
			$user = $this->getUser();
			$vote = $voteRepository->findVote($user, $post);
			if (!$vote || $vote->getType() == 0)
				$voteValue = "Not voted";
			else if ($vote->getType() == 1)
				$voteValue = "Liked";
			else
				$voteValue = "Disliked";

			$voteRepository->getUserReputation($user);

			$postEdit = $entityManager->getRepository(PostEdit::class)->getPostEdit($post);
			return $this->render('@E03Bundle/post.html.twig', [
				'post' => $post, 
				'user' => $user, 
				'vote' => $voteValue, 
				'post_edit' => $postEdit,
				'privileges' => $privileges
			]);
		} catch (Exception $e){
			$logger->error($e->getMessage());
			$this->addFlash('error', "Error showing post");
			return $this->redirectToRoute('ex01_homepage');
		}
    }

}
