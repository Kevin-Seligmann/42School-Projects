<?php

$filename = "ex01.txt";

$content = file($filename, FILE_IGNORE_NEW_LINES, null);

if ($content && isset($content[0]))
{
	$arr = explode(",", $content[0]);
	for ($i = 0, $size = count($arr); $i < $size; ++$i)
		echo $arr[$i]."\n";
}
