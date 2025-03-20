<?php

include_once('./HotBeverage.php');

class TemplateEngine {
	private static $templateFile = "template.html";

	public function createFile(HotBeverage $text)
	{
		if (!isset($text) || !file_exists(TemplateEngine::$templateFile))
			return ;

		$content = file_get_contents(TemplateEngine::$templateFile);
		if (!$content)
			return ;

		$rclass = new ReflectionClass($text);

		$result = preg_replace_callback(
			'/\{[\w]+\}/',
			function ($matches) use ($text, $rclass) 
			{
				$properties = $rclass->getProperties();
				foreach ($properties as $property){
					if ($matches[0] == "{{$property->getName()}}")
					{
						$getter = "get". ucfirst($property->getName());
						return $text->$getter();
					}
				}
				return $matches[0];
			},
			$content
		);

		$fileName = $rclass->getName().".html";
		file_put_contents($fileName, $result);
	}
}
