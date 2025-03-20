<?php

namespace App\Controller;

use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\HttpFoundation\Response;
use Symfony\Component\Routing\Attribute\Route;

class ArticleController extends AbstractController
{
    private static $articles = ["penguins", "seals"];

	#[Route('/e01/{article}', name: 'article')]
	public function index(string | null $article): Response
    {
        if (in_array($article, ArticleController::$articles))
            return $this->render("articles/$article.html.twig");
        return $this->render("articles/main.html.twig", ['articles' => ArticleController::$articles]);
    }
}
