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

function search_by_states($locations)
{
	global $states;
	global $capitals;

	$arr = explode(",", $locations);
    foreach ($arr as $key => $str) {
        $arr[$key] = trim($str);
    }

	$result = [];
	foreach($arr as $str)
	{
		$found_capital = null;
		$found_state = null;

		if (isset($states[$str]))
		{
			$found_capital = $capitals[$states[$str]];
			$found_state = $str;
		}
		else if (in_array($str, $capitals))
		{
			$found_capital = $str;
			$state_code = array_search($found_capital, $capitals);
			$found_state = array_search($state_code, $states);
		}

		if (isset($found_capital) && isset($found_state) && $found_state != null)
			$result[] = $found_capital." is the capital of ".$found_state.".";
		else 
			$result[] = $str." is neither a capital nor a state.";
	}
	return $result;
}
