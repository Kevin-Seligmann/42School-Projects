<?php

namespace App\EventListener;

use App\Entity\Post;
use Doctrine\Persistence\Event\LifecycleEventArgs;

class PostListener
{
    public function prePersist(LifecycleEventArgs $args): void
    {
        $entity = $args->getObject();

        if ($entity instanceof Post) {
            if ($entity->getCreated() === null) {
                $entity->setCreated(new \DateTime());
            }
        }
    }
}
