<?php

namespace App\Bundle\E04Bundle\Service;

use Symfony\Component\HttpFoundation\RequestStack;
use Symfony\Component\HttpFoundation\Session\SessionInterface;

class AnonymousManager {
	private $session;
	
    public function __construct(private RequestStack $requestStack)
    {
    }

    public function refreshAnonymousUser(): void
    {
		$request = $this->requestStack->getCurrentRequest();
		if (!$request->hasSession())
			return ;
		$this->session = $request->getSession();

        $currentTimestamp = time();
		$previousTimestamp = $this->session->get('anonymous_timestamp');
		$userName =  $this->session->get('anonymous_username');

		if (!isset($userName)){
			$this->setNewUser($userName);
			$this->session->set('anonymous_timestamp', $currentTimestamp);
			$this->session->set('anonymous_timer', 0);
			return ;
		}
		if (($currentTimestamp - $previousTimestamp) > 60){
            $this->setNewUser($userName);
			$previousTimestamp = $currentTimestamp;
		}
	    $this->session->set('anonymous_timestamp', $currentTimestamp);
		$this->session->set('anonymous_timer', $currentTimestamp - $previousTimestamp);

    }

    public function deleteAnonymousUser(): void
    {
		$request = $this->requestStack->getCurrentRequest();
		if (!$request->hasSession())
			return ;
		$this->session = $request->getSession();
		$this->session->remove('anonymous_username');
		$this->session->remove('anonymous_timestamp');
    }

	private function setNewUser($previousUser){
		$users = ["Cat", "Dog", "Frog", "Lion", "Serpent", "Cocodrile", "Parrot", "Ant"];

		$user = "";
		if (!isset($previousUser))
			$user = $users[array_rand($users)];
		else
			do {
				$user = $users[array_rand($users)];
			} while ($user === $previousUser);
		$this->session->set('anonymous_username',  $user);
	}
}
