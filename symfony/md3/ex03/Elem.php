<?php

class Elem {
	private static $allowedTags = ["meta","img","hr","br","html","head","body","title","h1","h2","h3","h4","h5","h6", "p", "span", "div"];
	private $element;
	private $content;

	public function __construct(string $element, string | Elem $content = null)
	{	
		if (!isset($element))
			return;
		$lowercase_element = strtolower($element);

		if (!in_array($lowercase_element, self::$allowedTags, true))
			return;
		if (isset($content))
			$this->content[] = $content;
		else
			$this->content = [];
		$this->element = $lowercase_element;
	}

	public function pushElement(string | Elem $content): void
	{
		$this->content[] = $content;
	}		

	public function getHTML(): string{
		$result = "<$this->element>";

		foreach ($this->content as $content)
		{
			if (gettype($content) == "string")
			{
				$result .= $content;
			}
			else
			{
				$tagContent = $content->getHTML();
				$result .= "\n".preg_replace('/^/m', "\t", $tagContent);
			}
		}

		$result .="</$this->element>\n";
		return $result;
	}
};
