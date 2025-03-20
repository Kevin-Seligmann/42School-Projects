<?php

$states = [
	'Oregon' => 'OR',
	'Alabama' => 'AL',
	'New Jersey' => 'NJ',
	'Colorado' => 'CO',
];

$capitals = [
	'OR' => 'Salem',
	'AL' => 'Montgomery',
	'NJ' => 'trenton',
	'KS' => 'Topeka',
];

function capital_city_from($state)
{
	global $states;
	global $capitals;

	if (isset($states[$state]))
		echo $capitals[$states[$state]]."\n";
	else
		echo "Unknown\n";
}
