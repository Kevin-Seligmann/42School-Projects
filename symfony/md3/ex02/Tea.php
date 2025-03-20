<?php

include_once("./HotBeverage.php");

class Tea extends HotBeverage {
	public function __construct(string $nom, float $price, float $resistance, private string $description, private string $comment)
	{
		parent::__construct($nom, $price, $resistance);
	}

	public function getDescription(){return $this->description;}
	public function getComment(){return $this->comment;}
}
