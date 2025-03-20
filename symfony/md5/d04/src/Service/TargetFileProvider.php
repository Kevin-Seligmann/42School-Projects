<?php

namespace App\Service;

class TargetFileProvider {

	public function __construct(private string $targetFile){}

	public function getTargetFile(): string {
		return $this->targetFile;
	}
}
