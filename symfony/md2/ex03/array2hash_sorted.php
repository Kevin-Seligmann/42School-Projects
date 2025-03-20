<?php

function array2hash_sorted($arr)
{
	$hash = [];

	foreach ($arr as $kv_pair)
		$hash[$kv_pair[0]] = $kv_pair[1];

	krsort($hash, SORT_STRING);
	
	return $hash;
}
