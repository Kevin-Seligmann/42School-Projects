<?php

include_once('./Text.php');
include_once('./TemplateEngine.php');

$engine = new TemplateEngine();
$text = new Text(["one", "two"]);
$text->append("three");

$engine->createFile("target.html", $text);
