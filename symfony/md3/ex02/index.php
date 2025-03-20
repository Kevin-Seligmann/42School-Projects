<?php

include_once("./Coffee.php");
include_once("./Tea.php");
include_once("./TemplateEngine.php");

$coffee = new Coffee("Cafe con chocolate", 5.4, 3, "Un cafe con chocolate caliente", "Cafe + Azucar");
$tea = new Tea("Bubble Tea", 8, 2.5, "Un té con burbujas de tapioca", "Nunca comí esto, en verdad");

$engine = new TemplateEngine();

$engine->createFile($coffee);
$engine->createFile($tea);
