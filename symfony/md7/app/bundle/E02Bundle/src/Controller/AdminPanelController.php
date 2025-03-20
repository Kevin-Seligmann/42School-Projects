<?php

namespace App\Bundle\E02Bundle\Controller;

use App\Bundle\E01Bundle\Entity\E01User;
use Exception;
use Doctrine\ORM\EntityManagerInterface;
use Psr\Log\LoggerInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;

class AdminPanelController extends AbstractController {
	#[Route('/admin', name: 'ex02_admin')]
    public function index(EntityManagerInterface $entityManager, LoggerInterface $logger): Response
	{
		$this->denyAccessUnlessGranted('ROLE_ADMIN');

        $users = [];
        try {
            $usersData = $entityManager->getRepository(E01User::class)->findAll();
            foreach ($usersData as $user)
                $users[] = $user->getUsername();
        } catch (Exception $e){
            $logger->error($e->getMessage());
            $this->addFlash('error', 'Unknown error on admin panel retrieving users');
            return $this->render("@E01Bundle/homepage.html.twig");
        }
        return $this->render("@E02Bundle/admin.html.twig", [
            'users' => $users
        ]);
    }

	#[Route('/admin/delete/{username}', name: 'ex02_delete_user')]
    public function deleteUser(string $username, EntityManagerInterface $entityManager, LoggerInterface $logger): Response
	{
		$this->denyAccessUnlessGranted('ROLE_ADMIN');
         
        $ownUser = $this->getUser();
        if ($ownUser->getUsername() == $username){
            $this->addFlash('error', 'Cant delete own admin user');
            return $this->redirectToRoute('ex02_admin');
        }
    
        try {
            $user = $entityManager->getRepository(E01User::class)->findOneBy(['username' => $username]);
            if (!$user){
                $this->addFlash('error', 'Unknown error on admin panel deleting user');
                return $this->redirectToRoute('ex02_admin');
            }
            $entityManager->remove($user);
            $entityManager->flush();
        } catch (Exception $e){
            $logger->error($e->getMessage());
            $this->addFlash('error', 'Unknown error on admin panel deleting user');
        }
        return $this->redirectToRoute('ex02_admin');
    }
}
