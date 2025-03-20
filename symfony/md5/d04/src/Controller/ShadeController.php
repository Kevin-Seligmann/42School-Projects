<?php

namespace App\Controller;

use App\Service\ColorAmountProvider;
use Symfony\Bundle\FrameworkBundle\Controller\AbstractController;
use Symfony\Component\Routing\Attribute\Route;
use Symfony\Component\HttpFoundation\Response;

class ShadeController extends AbstractController
{
    #[Route('/e03', name: 'color')]
    public function index(ColorAmountProvider $colorAmountProvider): Response
    {
		$colorQty = $colorAmountProvider->getColorAmount();
		if ($colorQty < 0)
			$colorQty == 1;
		
		$colors = [];
		$colors['names'] = ['black', 'red', 'blue', 'green'];
		$colors['amount'] = $colorQty;
		$colors['black'] = [];
		$colors['red'] = [];
		$colors['blue'] = [];
		$colors['green'] = [];



		for ($i = 0; $i < $colorQty; $i ++)
		{
			$step = (255 / $colorQty) * $i;
			
			$colors['black'][$i]['r'] = $step;
			$colors['black'][$i]['g'] = $step;
			$colors['black'][$i]['b'] = $step;

			$colors['red'][$i]['r'] = 255 - $step;
			$colors['red'][$i]['g'] = 0;
			$colors['red'][$i]['b'] = 0;

			$colors['green'][$i]['r'] = 0;
			$colors['green'][$i]['g'] = 255 - $step;
			$colors['green'][$i]['b'] = 0;

			$colors['blue'][$i]['r'] = 0;
			$colors['blue'][$i]['g'] = 0;
			$colors['blue'][$i]['b'] = 255 - $step;

		}

		return $this->render("color/color.html.twig",[
			'colors' => $colors
		]);
    }
}
