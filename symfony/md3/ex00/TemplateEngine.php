<?php

class TemplateEngine {
	public function createFile($fileName, $templateName, $parameters)
	{
		if (!isset($parameters) || !file_exists(($templateName)))
			return ;

		$content = file_get_contents($templateName);
		if (!$content)
			return ;

		$result = preg_replace_callback(
			'/\{[\w]+\}/',
			function ($matches) use ($parameters) 
			{
				if (isset($parameters[$matches[0]]))
					return $parameters[$matches[0]];
				return
					$matches[0];
			},
			$content
		);

		file_put_contents($fileName, $result);
	}
}
