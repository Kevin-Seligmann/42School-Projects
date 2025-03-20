<?php

namespace App\Bundle\E03Bundle\Entity;

use App\Bundle\E01Bundle\Entity\E01User;
use App\Bundle\E03Bundle\Repository\E03PostRepository;
use Doctrine\DBAL\Types\Types;
use Doctrine\ORM\Mapping as ORM;

#[ORM\Entity(repositoryClass: E03PostRepository::class)]
class E03Post
{
    #[ORM\Id]
    #[ORM\GeneratedValue]
    #[ORM\Column]
    private ?int $id = null;

    #[ORM\Column(length: 50)]
    private ?string $title = null;

    #[ORM\Column(type: Types::TEXT)]
    private ?string $content = null;

    #[ORM\Column(type: Types::DATETIME_MUTABLE)]
    private ?\DateTimeInterface $created = null;

    #[ORM\ManyToOne(targetEntity: E01User::class, cascade: ['remove'])]
    #[ORM\JoinColumn(nullable: false)]
    private ?E01User $author = null;

    private int $likes = 0;
    private int $dislikes = 0;

    public function getId(): ?int
    {
        return $this->id;
    }

    public function getTitle(): ?string
    {
        return $this->title;
    }

    public function setTitle(string $title): static
    {
        $this->title = $title;

        return $this;
    }

    public function getContent(): ?string
    {
        return $this->content;
    }

    public function setContent(string $content): static
    {
        $this->content = $content;

        return $this;
    }

    public function getCreated(): ?\DateTimeInterface
    {
        return $this->created;
    }

    public function setCreated(\DateTimeInterface $created): static
    {
        $this->created = $created;

        return $this;
    }

    public function getAuthor(): ?E01User
    {
        return $this->author;
    }

    public function setAuthor(?E01User $author): static
    {
        $this->author = $author;

        return $this;
    }

    public function setDislikes(int $dislikes){
        $this->dislikes =  $dislikes;
    }

    public function getDislikes(): int {
        return $this->dislikes;
    }

    public function setLikes(int $likes){
        $this->likes =  $likes;
    }
    
    public function getLikes(): int {
        return $this->likes;
    }
}
