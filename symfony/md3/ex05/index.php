<?php

include_once("./TemplateEngine.php");
include_once("./Elem.php");

$html = new Elem('html');
$body = new Elem('BodY');
$head = new Elem('head');
$meta = new Elem('meta', null, ["charSet" => "uTf-8"]);
$title = new Elem('title', "Title");
$table = new Elem('table');
$ol = new Elem('ol');
$ul = new Elem('ul');
$p = new Elem('p', "Una table");

$head->pushElement($meta);
$head->pushElement($title);

$html->pushElement($head);
$html->pushElement($body);

$body->pushElement($p);
$body->pushElement($table);
$body->pushElement($ol);
$body->pushElement($ul);

$li = new Elem("li", "ordered item");
$li->pushElement(new Elem('div', "test"));

$ol->pushElement(new Elem("li"));
$ol->pushElement(new Elem("li", "ordered item"));
$ol->pushElement($li);

$ul->pushElement(new Elem("li"));
$ul->pushElement(new Elem("li", "unordered item"));

$testelem = $html;
echo $testelem->getHTML();

if ($testelem->validPage())
	echo "valid\n";
else
	echo "invalid\n";

