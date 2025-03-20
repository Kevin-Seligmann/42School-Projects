<?php

include_once("./TemplateEngine.php");
include_once("./Elem.php");

$elem = new Elem('html');
$body = new Elem('body');
$body->pushElement(new Elem('p', 'Lorem ipsum', ['class' => 'text-muted']));
$elem->pushElement($body);
$elem->pushElement($body);
$elem->pushElement($body);
$elem->pushElement($body);

echo $elem->getHTML();


$eng = new TemplateEngine($elem);
$eng->createFile("target.html");

try {
	$elem = new Elem('undefined');
} catch (Exception $e){
	echo $e->getMessage()."\n";
}
