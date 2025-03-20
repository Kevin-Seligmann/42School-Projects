<?php

include_once("./TemplateEngine.php");
include_once("./Elem.php");

$elem = new Elem('html');
$body = new Elem('body');
$body->pushElement(new Elem('p', 'Lorem ipsum'));
$elem->pushElement($body);
echo $elem->getHTML();

$eng = new TemplateEngine($elem);
$eng->createFile("target.html");
