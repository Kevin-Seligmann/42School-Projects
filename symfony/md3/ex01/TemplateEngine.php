<?php

include_once('./Text.php');

class TemplateEngine {
	public function createFile($fileName, $text)
	{
		if (!isset($fileName) || !isset($text))
			return ;
		file_put_contents($fileName, $text->readData());
	}
}
