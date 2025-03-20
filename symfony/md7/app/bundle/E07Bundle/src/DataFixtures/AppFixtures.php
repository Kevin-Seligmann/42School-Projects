<?php

namespace App\Bundle\E07Bundle\DataFixtures;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E03Bundle\Entity\E03Post;
use App\Bundle\E05Bundle\Entity\Vote;
use Faker\Factory;
use DateTime;
use Doctrine\Bundle\FixturesBundle\Fixture;
use Doctrine\Persistence\ObjectManager;
use Symfony\Component\PasswordHasher\Hasher\UserPasswordHasherInterface;

class AppFixtures extends Fixture {
    private UserPasswordHasherInterface $passwordHasher;

    public function __construct(UserPasswordHasherInterface $passwordHasher)
    {
        $this->passwordHasher = $passwordHasher;
    }

    public function load(ObjectManager $manager): void
    {
		$faker = Factory::create();

		$userAdmin = $this->createUser('admin', '00Admin!', $manager);
		$userAdmin->setRoles(['ROLE_ADMIN']);
		$user01 = $this->createUser('01user', '01User!', $manager);
		$user02 = $this->createUser('02user', '02User!', $manager);
		$user03 = $this->createUser('03user', '03User!', $manager);
		$user04 = $this->createUser('04user', '04User!', $manager);
		$user05 = $this->createUser('05user', '05User!', $manager);

		$post01 = $this->createPost($user01, 'POST 01. Title of the post.', $manager, $faker);
		$post02 = $this->createPost($user01, 'POST 02. Title of the post.',$manager, $faker);
		$post03 = $this->createPost($user03, 'POST 03. Title of the post.', $manager, $faker);
		$post04 = $this->createPost($user04, 'POST 04. Title of the post.', $manager, $faker);
		$post05 = $this->createPost($user04, 'POST 05. Title of the post.', $manager, $faker);
		$post06 = $this->createPost($user05, 'POST 06. Title of the post.', $manager, $faker);

		// User 1 10 points
		// User 2 0 points
		// User 3 2 points
		// User 4 8 points
		// User 5 0 points

		$this->votePost($user01, $post01, $manager, 1);
		$this->votePost($user01, $post02, $manager, 1);
		$this->votePost($user01, $post03, $manager, 1);
		$this->votePost($user01, $post04, $manager, 1);
		$this->votePost($user01, $post05, $manager, -1);

		$this->votePost($user02, $post01, $manager, 1);
		$this->votePost($user02, $post02, $manager, 1);
		$this->votePost($user02, $post03, $manager, -1);
		$this->votePost($user02, $post04, $manager, 1);
		$this->votePost($user02, $post05, $manager, 1);

		$this->votePost($user03, $post01, $manager, 1);
		$this->votePost($user03, $post02, $manager, 1);
		$this->votePost($user03, $post03, $manager, 1);
		$this->votePost($user03, $post04, $manager, 1);
		$this->votePost($user03, $post05, $manager, 1);

		$this->votePost($user04, $post01, $manager, 1);
		$this->votePost($user04, $post02, $manager, 1);
		$this->votePost($user04, $post03, $manager, 1);
		$this->votePost($user04, $post04, $manager, 1);
		$this->votePost($user04, $post05, $manager, 1);

		$this->votePost($user05, $post01, $manager, 1);
		$this->votePost($user05, $post02, $manager, 1);
		//$this->votePost($user05, $post03, $manager);
		$this->votePost($user05, $post04, $manager, 1);
		$this->votePost($user05, $post05, $manager, 1);

        $manager->flush();
    }

	private function createUser(string $username, string $password, ObjectManager $manager){
		$user = new E01User();
		$user->setUsername($username);
        $hashedPassword = $this->passwordHasher->hashPassword($user, $password);
        $user->setPassword($hashedPassword);
		$manager->persist($user);
		return $user;
	}

	private function createPost(E01User $user, string $title, ObjectManager $manager, $faker){
		$post = new E03Post();
		$post->setAuthor($user);
		$post->setTitle($title);
		$timestamp = mt_rand(strtotime('-1 year'), time());
		$post->setCreated((new DateTime())->setTimestamp($timestamp));
		$post->setContent($faker->paragraphs(3, true));
		$manager->persist($post);
		return $post;
	}

	private function votePost(E01User $user, E03Post $post, ObjectManager $manager, int $voteValue){
		$vote = new Vote();
		$vote->setVoter($user);
		$vote->setPost($post);
		$vote->setType($voteValue);
		$manager->persist($vote);
	}
}
