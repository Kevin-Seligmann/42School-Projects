<?php

namespace App\Bundle\E06Bundle\Entity;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E03Bundle\Entity\E03Post;
use App\Bundle\E06Bundle\Repository\PostEditRepository;
use Doctrine\DBAL\Types\Types;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: PostEditRepository::class)]
class PostEdit
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\Column(type: Types::DATETIME_MUTABLE)]
    private ?\DateTimeInterface $date = null;

    #[ORM\ManyToOne(targetEntity: E01User::class, cascade: ['remove'])]
    #[ORM\JoinColumn(nullable: false)]
    private ?E01User $editor = null;

    #[ORM\OneToOne(cascade: ['persist', 'remove'])]
    #[ORM\JoinColumn(nullable: false)]
    private ?E03Post $post = null;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getDate(): ?\DateTimeInterface
    {
        return $this->date;
    }

    public function setDate(\DateTimeInterface $date): static
    {
        $this->date = $date;

        return $this;
    }

    public function getEditor(): ?E01User
    {
        return $this->editor;
    }

    public function setEditor(?E01User $editor): static
    {
        $this->editor = $editor;

        return $this;
    }

    public function getPost(): ?E03Post
    {
        return $this->post;
    }

    public function setPost(E03Post $post): static
    {
        $this->post = $post;

        return $this;
    }
}
