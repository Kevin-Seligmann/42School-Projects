<?php

class HotBeverage {
	protected function __construct(protected string $nom, protected float $price, protected float $resistance){}

	public function getNom(){return $this->nom;}
	public function getPrice(){return $this->price;}
	public function getResistance(){return $this->resistance;}
}
