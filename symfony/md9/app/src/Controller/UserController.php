<?php

namespace App\Controller;

use App\Entity\User;
use App\Form\PostForm;
use App\Entity\Post;
use Doctrine\ORM\EntityManagerInterface;
use Exception;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Bundle\SecurityBundle\Security;
use Symfony\Component\HttpFoundation\JsonResponse;
use Symfony\Component\HttpFoundation\Request;
use Symfony\Component\PasswordHasher\Hasher\UserPasswordHasherInterface;
use Symfony\Component\Routing\Annotation\Route;
use Symfony\Component\Security\Http\Authentication\AuthenticationUtils;

class UserController extends AbstractController {
	#[Route('/login', name: 'loginAction')]
	public function loginAction(){

		return $this->render('login.html.twig');
	}

	#[Route('/login_attempt', name: 'loginAttempt')]
	public function loginAttempt(AuthenticationUtils $authenticationUtils){
		$error = $authenticationUtils->getLastAuthenticationError();
		if ($error && $error->getMessage())
			$response = new JsonResponse(["error" => $error->getMessage()]);
		else {
			$response = new JsonResponse(["error" => "Unknown error"]);
		}	
		return $response;
	}

	#[Route('/register_attempt', name: 'registerAttempt')]
	public function registerAttempt(Request $request, UserPasswordHasherInterface $passwordHasher, EntityManagerInterface $entityManager){
        $username = $request->request->get('_username');
		$password = $request->request->get('_password');

		if (!isset($username) || !$username || strlen($username) < 3)
			return new JsonResponse(['response' => 'Username too short, at least 3 characters']);
		if (strlen($username) > 30)
			return new JsonResponse(['response' => 'Username too long']);

		if (!isset($password) || !$password || strlen($password) < 8)
			return new JsonResponse(['response' => 'Username too short, at least 8 characters']);
		if (strlen($password) > 30)
			return new JsonResponse(['response' => 'Password too long']);

		$user = new User();
		$user->setUsername($username);
		$hashedPassword = $passwordHasher->hashPassword(
			$user,
			$password
		);
		$user->setPassword($hashedPassword);

		try {
			$entityManager->persist($user);
			$entityManager->flush();
			return new JsonResponse(['response' => 'User registered']);
		} catch (Exception $e){
			return new JsonResponse(['response' => 'Couldn\'t register the user']);
		}
	}

	#[Route('/logout', name: 'logoutAttempt')]
	public function logoutAttempt(Security $security){
		$this->denyAccessUnlessGranted('ROLE_USER');
		$formView = $this->renderView('login.html.twig');

		if ($this->getUser()){
			$security->logout(false);
			return new JsonResponse(['response' => "User logged out", 'form' => $formView]);
		}
		return new JsonResponse(['response' => "Cannot log out", 'form' => $formView]);
	}

}
