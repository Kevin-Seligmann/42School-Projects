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
		$lineSkipElements = ["head", "body", "html", "table", "ol", "ul", "div", "li", "tr", "th", "td"];
		$skipLine = in_array($this->element, $lineSkipElements);

		$result = "<$this->element";
		foreach ($this->attributes as $attribute => $value)
			$result .= " $attribute=\"$value\"";
		$result .= ">";

		if ($skipLine)
			$result .= "\n";

		foreach ($this->content as $content)
		{
			if (gettype($content) == "string")
				$tagContent = $content;
			else
				$tagContent = $content->getHTML();
			if ($skipLine)
				$result .= preg_replace('/^/m', "\t", $tagContent)."\n";
			else
				$result .= $tagContent;
		}

		$result .= "</$this->element>\n";
		return $result;
	}

	public function validPage(): bool {
		if ($this->element != "html")
			return false; 
		if (sizeof ($this->content) != 2)
			return false;

		$head_tag = $this->content[0];
		$body_tag = $this->content[1];
		if (!($head_tag instanceof self) || $head_tag->element != "head")
			return false;
		if (!($body_tag instanceof self) || $body_tag->element != "body")
			return false;
		if (!$head_tag->validateHead())
			return false;
		if (!$body_tag->validateEmbeddableTag())
			return false;	
		return true;
	}

	private function validateEmbeddableTag(): bool {
		$forbidden_tags = ["html", "head", "body", "title"];
	
		foreach ($this->content as $content)
		{
			if ($content instanceof self)
			{
				if (in_array($content->element, $forbidden_tags)){
					return false;}
				else if ($content->element == "table"){
					if (!$content->validateTable())
						return false;}
				else if (($content->element == "ol" || $content->element == "ul")){
					if (!$content->validateList())
						return false;}
				else if ($content->element == "p"){
					if (!$content->validatetextOnly())
						return false;}
				else if (!$content->validateEmbeddableTag()){
					return false;}
			}
		}
		return true;
	}

	private function validateHead(): bool {
		$title_found = 0;
		$meta_found = 0;

		foreach ($this->content as $content)
		{
			if ($content instanceof self && $content->element == "title" && $content->validateTextOnly())
				$title_found ++;
			else if ($content instanceof self && $content->element == "meta" && $content->validateMeta())
				$meta_found ++;
			else
				return false;
		}
		return $title_found == 1 && $meta_found == 1;
	}

	private function validatetextOnly(): bool {
		foreach ($this->content as $content)
		{
			if ($content instanceof self)
				return false;
		}
		return true;
	}

	private function validateMeta(): bool {
		if (sizeof ($this->content) > 0)
			return false;
		if (sizeof($this->attributes) != 1)
			return false;
		$lowerAttributes = array_change_key_case($this->attributes, CASE_LOWER);
		return isset($lowerAttributes["charset"]) && strtolower($lowerAttributes["charset"]) == "utf-8";
	}

	private function validateTable(): bool {
		foreach ($this->content as $content)
		{
			if (!($content instanceof self))
				return false;
			if ($content->element != "tr")
				return false;
			if  (!isset($content->content))
				continue ;
			foreach ($content->content as $row_content)
			{
				if (!($row_content instanceof self))
					return false;
				if ($row_content->element != "th" && $row_content->element != "td")
					return false;
				if (!$row_content->validateEmbeddableTag())
					return false;
			}
		}
		return true;
	}

	private function validateList(): bool {
		foreach ($this->content as $content)
		{
			if (!($content instanceof self)) 
				return false;
			if ($content->element != "li")
				return false;
			if (!$content->validateEmbeddableTag())
				return false;
		}
		return true;
	}
};
