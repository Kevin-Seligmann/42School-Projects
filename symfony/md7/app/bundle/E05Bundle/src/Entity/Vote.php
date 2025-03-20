<?php

namespace App\Bundle\E05Bundle\Entity;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E03Bundle\Entity\E03Post;
use App\Bundle\E05Bundle\Repository\VoteRepository;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: VoteRepository::class)]
class Vote
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\Column(nullable: true)]
    private ?int $type = null;

    #[ORM\ManyToOne(targetEntity: E01User::class, cascade: ['remove'])]
    #[ORM\JoinColumn(nullable: false)]
    private ?E01User $voter = null;

    #[ORM\ManyToOne(targetEntity: E03Post::class, cascade: ['remove'])]
    #[ORM\JoinColumn(nullable: false)]
    private ?E03Post $post = null;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getType(): ?int
    {
        return $this->type;
    }

    public function setType(?int $type): static
    {
        $this->type = $type;

        return $this;
    }

    public function getVoter(): ?E01User
    {
        return $this->voter;
    }

    public function setVoter(?E01User $voter): static
    {
        $this->voter = $voter;

        return $this;
    }

    public function getPost(): ?E03Post
    {
        return $this->post;
    }

    public function setPost(?E03Post $post): static
    {
        $this->post = $post;

        return $this;
    }
}
