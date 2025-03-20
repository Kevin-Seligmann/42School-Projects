<?php

namespace App\Bundle\E01Bundle\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Bundle\SecurityBundle\Security;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;
use Symfony\Component\Security\Http\Authentication\AuthenticationUtils;

class LoginController extends AbstractController {
	#[Route('/login', name: 'ex01_login_form')]
    public function index(AuthenticationUtils $authenticationUtils): Response
	{
		if ($this->getUser())
            return $this->redirectToRoute('ex01_homepage');
	
		$error = $authenticationUtils->getLastAuthenticationError();
		if ($error != null)
			$this->addFlash('error', $error->getMessage());
		$lastUsername = $authenticationUtils->getLastUsername();
		return $this->render('@E01Bundle/login.html.twig', ['username' => $lastUsername]);
    }

	#[Route('/logout', name: 'ex01_logout')]
	public function logout(Security $security){
		$this->denyAccessUnlessGranted('ROLE_USER');

		$security->logout(false);
		return $this->redirectToRoute('ex01_homepage');
	}
}
