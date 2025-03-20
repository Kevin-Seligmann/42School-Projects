<?php

include('./TemplateEngine.php');

$engine = new TemplateEngine();

$engine->createFile("target.html","book_description.html",
["{nom}" => "PH+", 
			"{auteur}" => "Kevin", 
			"{description}" => "Un libro bonito", 
			"{prix}" => "20 cents"]);
