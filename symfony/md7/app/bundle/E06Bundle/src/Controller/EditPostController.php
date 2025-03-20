<?php

namespace App\Bundle\E06Bundle\Controller;

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
use Symfony\Bundle\SecurityBundle\Security;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;

class EditPostController extends AbstractController {
	#[Route('/post/edit/{id}', name: 'ex06_edit_post')]
	public function edit_form(int $id, Request $request, EntityManagerInterface $entityManager, LoggerInterface $logger, UserPrivilegeService $privileges)
	{
		$this->denyAccessUnlessGranted('ROLE_USER');
		
		try {
			$user = $this->getUser();
			$post = $entityManager->find(E03Post::class, $id);
			if (!$post)
				return $this->redirectToRoute('ex03_post', ['id' => $id]);
			
			$entityManager->getRepository(Vote::class)->getUserReputation($user);
			if (!$privileges->canEditPost($user, $post)){
				$this->addFlash('error', "Can't edit this post");
				return $this->redirectToRoute('ex03_post', ['id' => $id]);
			}

			$form = $this->createForm(PostForm::class, $post);
			$form->handleRequest($request);
			if ($form->isSubmitted() && $form->isValid()){
				$editRepository = $entityManager->getRepository(PostEdit::class);
				$edit = $editRepository->getPostEdit($post);
				if (!$edit){
					$edit = new PostEdit();
					$edit->setPost($post);
				}
				$edit->setEditor($this->getUser());
				$edit->setDate(new DateTime());
				$entityManager->persist($edit);
				$entityManager->persist($post);
				$entityManager->flush();
				$this->addFlash('success', "Post updated");
			}
			return $this->render("@E06Bundle/edit_post.html.twig", ['form' => $form, 'post' => $post]);
		} catch (Exception $e){
			$logger->error($e->getMessage());
			$this->addFlash('error', "Error on post update");
			return $this->redirectToRoute('ex03_post', ['id' => $id]);
		}
    }


}
