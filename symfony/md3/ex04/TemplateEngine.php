<?php

include_once('./Elem.php');

class TemplateEngine {

	public function __construct(private Elem $elem){}

	public function createFile(string $fileName)
	{
		if (!isset($this->elem))
			return ;
		file_put_contents($fileName, $this->elem->getHTML());
	}
}
