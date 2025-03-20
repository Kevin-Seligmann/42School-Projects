<?php

function array2hash($arr)
{
	$hash = [];

	foreach ($arr as $kv_pair)
		$hash[$kv_pair[1]] = $kv_pair[0];
	return $hash;
}
