<?php

namespace App\Bundle\E05Bundle\Controller;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E03Bundle\Entity\E03Post;
use App\Bundle\E03Bundle\Form\PostForm;
use App\Bundle\E05Bundle\Entity\Vote;
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

class VoteController extends AbstractController {
	#[Route('/vote/{userId}/{postId}/{voteValue}', name: 'ex05_vote')]
	public function index(int $userId, int $postId, int $voteValue, EntityManagerInterface $entityManager, LoggerInterface $logger, UserPrivilegeService $privileges)
	{
		$this->denyAccessUnlessGranted('ROLE_USER');

		try {
			$user = $this->getUser();
			$post = $entityManager->find(E03Post::class, $postId);

			$entityManager->getRepository(Vote::class)->getUserReputation($user);
			if (($voteValue != 1 && $voteValue != -1) || !$user || !$post || $user->getId() != $userId)
				return $this->redirectToRoute('ex03_post', ['id' => $postId]);
			
			if ($voteValue == 1 && !$privileges->canLikePosts($user)){
				$this->addFlash('error', "Can't like this post");
				return $this->redirectToRoute('ex03_post', ['id' => $postId]);
			}

			if ($voteValue == -1 && !$privileges->canDislikePosts($user)){
				$this->addFlash('error', "Can't dislike this post");
				return $this->redirectToRoute('ex03_post', ['id' => $postId]);
			}

			$vote = $entityManager->getRepository(Vote::class)->findVote($user, $post);
			if (!$vote){
				$vote = new Vote();
				$vote->setPost($post);
				$vote->setVoter($user);
			}
			if (!$vote->getType() || $vote->getType() == 0 || $vote->getType() != $voteValue)
				$vote->setType($voteValue);
			else if ($vote->getType() == $voteValue)
				$vote->setType(0);
			$entityManager->persist($vote);
			$entityManager->flush();
		} catch (Exception $e){
			$logger->error($e->getMessage());
			$this->addFlash('error', "Error voting");
			return $this->redirectToRoute('ex03_post', ['id' => $postId]);
		}
		return $this->redirectToRoute('ex03_post', ['id' => $postId]);
    }
}
