<?php

namespace App\Bundle\E01Bundle\Controller;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E03Bundle\Entity\E03Post;
use App\Bundle\E04Bundle\Service\AnonymousManager;
use App\Bundle\E05Bundle\Entity\Vote;
use Doctrine\ORM\EntityManagerInterface;
use Exception;
use Psr\Log\LoggerInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;

class HomepageController extends AbstractController {
	#[Route('/homepage', name: 'ex01_homepage')]
    public function index(EntityManagerInterface $entityManager, LoggerInterface $logger): Response
	{
        $posts  = [];
        
        try {
            $posts = $entityManager->getRepository(E03Post::class)->findBy([], ['created' => 'DESC']);
            $voteRepository = $entityManager->getRepository(Vote::class);
            foreach ($posts as $post){
               $voteRepository->getPostLikes($post);
               $voteRepository->getPostDislikes($post);
               $voteRepository->getUserReputation($post->getAuthor());
            }

            $user = $this->getUser();
            if ($user)
                $voteRepository->getUserReputation($user);
        } catch (Exception $e){
            $this->addFlash('error', "error retrieving posts");
            $logger->error($e->getMessage());
        }
        return $this->render("@E01Bundle/homepage.html.twig", ['posts' => $posts]);
    }

}
