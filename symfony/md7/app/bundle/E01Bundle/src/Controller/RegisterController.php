<?php

namespace App\Bundle\E01Bundle\Controller;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E01Bundle\Form\RegisterForm;
use Psr\Log\LoggerInterface;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\PasswordHasher\Hasher\UserPasswordHasherInterface;
use Symfony\Component\Routing\Attribute\Route;
use Symfony\Component\HttpFoundation\Request;
use Doctrine\DBAL\Exception\UniqueConstraintViolationException;
use Doctrine\ORM\EntityManagerInterface;
use Exception;

class RegisterController extends AbstractController {
	#[Route('/register', name: 'ex01_register_form')]
    public function index(Request $request, EntityManagerInterface $entityManager, LoggerInterface $logger, UserPasswordHasherInterface $passwordHasher): Response
	{
		if ($this->getUser())
            return $this->redirectToRoute('ex01_homepage');
		
		$user = new E01User();
		$form = $this->createForm(RegisterForm::class, $user);
		$form->handleRequest($request);
		if ($form->isSubmitted() && $form->isValid())
		{
			$hashedPassword = $passwordHasher->hashPassword(
				$user,
				$user->getPassword()
			);
			$user->setPassword($hashedPassword);
			try {
				$entityManager->persist($user);
				$entityManager->flush();
				$this->addFlash('success', 'Registration completed');
				return $this->redirectToRoute("ex01_login_form");
			} catch (UniqueConstraintViolationException $e){
				$this->addFlash('error', 'Username already taken');
			} catch (Exception $e){
				$this->addFlash('error', 'Unexpected error');
				$logger->error($e->getMessage());
			}
		}
        return $this->render("@E01Bundle/register.html.twig", ['form' => $form]);
    }
}
