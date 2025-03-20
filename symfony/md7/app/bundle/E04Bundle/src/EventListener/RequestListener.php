<?php

namespace App\Bundle\E04Bundle\EventListener;

use App\Bundle\E04Bundle\Service\AnonymousManager;
use Symfony\Bundle\SecurityBundle\Security;
use Symfony\Component\EventDispatcher\Attribute\AsEventListener;
use Symfony\Component\HttpKernel\Event\RequestEvent;

#[AsEventListener(event: RequestEvent::class)]
final class RequestListener {
    public function __construct(private AnonymousManager $anonymousManager, private Security $security)
    {
    }

    public function __invoke(RequestEvent $event)
    {
		if (!$event->isMainRequest()) {
            return;
        }
		if ($this->security->getUser()){
			$this->anonymousManager->deleteAnonymousUser();
		}
		$this->anonymousManager->refreshAnonymousUser();
    }
}
