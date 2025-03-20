<?php

namespace App\Bundle\E07Bundle\Service;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E03Bundle\Entity\E03Post;

class UserPrivilegeService {
    public function canEditPost(E01User $user, E03Post $post)
    {
        return $user->getReputation() >= 9 || $this->isOwnPost($user, $post) || $this->hasAllPrivileges($user);
    }

    public function canLikePosts(E01User $user)
    {
        return $user->getReputation() >= 3 || $this->hasAllPrivileges($user);
    }

    public function canDislikePosts(E01User $user)
    {
        return $user->getReputation() >= 6 || $this->hasAllPrivileges($user);
    }

	private function hasAllPrivileges(E01User $user){
		return in_array('ROLE_ADMIN', $user->getRoles());
	}

	private function isOwnPost(E01User $user, E03Post $post){
        return $post->getAuthor() && $user->getId() === $post->getAuthor()->getId();
	}
}
