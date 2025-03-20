<?php

namespace App\Service;

class ColorAmountProvider {

	public function __construct(private int $colorAmount){}

	public function getColorAmount(): int {
		return $this->colorAmount;
	}
}
