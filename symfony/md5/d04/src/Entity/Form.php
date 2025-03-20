<?php

namespace App\Entity;

class Form {
	protected string $message;
	protected bool $putDate;

	public function getMessage(): string
    {
        return $this->message;
    }

	public function getPutDate(): int
    {
        return $this->putDate;
    }

	public function setMessage(string $message): void
    {
        $this->message = $message;
    }

	public function setPutDate(string $putDate): void
    {
        $this->putDate = $putDate;
    }
}
