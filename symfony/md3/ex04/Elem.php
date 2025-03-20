<?php

class MyException extends Exception {}

class Elem {
	private static $allowedTags = [
		"meta","img","hr","br","html",
		"head","body","title","h1","h2",
		"h3","h4","h5","h6", "p", 
		"span", "div", "table", "tr", 
		"th", "td", "ul", "ol", "li"
	];

	private $element;
	private $content;
	private $attributes;

	public function __construct(string $element, string | Elem $content = null, array $attributes = null)
	{
		if (!isset($element))
			throw new MyException("Invalid element");
		$lowercase_element = strtolower($element);
		if (!in_array($lowercase_element, self::$allowedTags, true))
			throw new MyException("Invalid element ".$lowercase_element);
		$this->element = $lowercase_element;
		if (isset($content))
			$this->content[] = $content;
		else
			$this->content = [];
		if (isset($attributes))
			$this->attributes = $attributes;
		else
			$this->attributes = [];
	}

	public function pushElement(string | Elem $content): void
	{
		$this->content[] = $content;
	}

	public function getHTML(): string{
		$result = "<$this->element";
		foreach ($this->attributes as $attribute => $value)
			$result .= " $attribute=\"$value\"";
		$result .= ">";

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
