<?php
define("MAX_COLS",     18);

$filename = "ex06.txt";
$output_file = "mendeleiev.html"; 
$file_content = "";

$content = file($filename, FILE_IGNORE_NEW_LINES, null);

if ($content)
{

	$elements = [];
	foreach ($content as $element)
	{
		$element_array = explode("=", $element);
		$element_name = trim($element_array[0], " ");
		$element_properties = explode(",", $element_array[1]);
		$position = trim(explode(":", $element_properties[0])[1], " ");
		$number = trim(explode(":", $element_properties[1])[1], " ");
		$small = trim(explode(":", $element_properties[2])[1], " ");
		$molar = trim(explode(":", $element_properties[3])[1], " ");
		$electron = trim(explode(":", $element_properties[4])[1], " ");

		$elements[$number] = [$position, $element_name, $small, $molar, $electron];
	}

	$file_content .=
	"<head>
		<style>	
			body {
				background-color: black;
			}
			ul {
				margin: 0;
				padding: 2px;
			}
			li {
				list-style-type: none;
				margin: 0;
				padding: 0;
			}
			table {
				border-collapse: collapse;
				border: 1px solid black;
				margin: 0 auto;
			}
			td {
				margin: 0px;
				padding: 0px;
				border: 1px solid black;
				width: 80px;
				height: 80px;
				font-size: 0.6rem;
			}
			.emptyCell {
				border: 0px;
				background-color: rgb(195, 195, 195);
			}

			.elementCell {
				background-color: rgb(159, 235, 210);
			}
		</style>
	</head>\n";
	$file_content .= "<body>\n";
	$file_content .= "<table>\n";
	$col = 0;
	foreach ($elements as $ind => $element)
	{
		if ($col == 0)
			$file_content .= "<tr>\n";
		while ($col != $element[0])
		{
			$file_content .=  "<td class=\"emptyCell\"></td>\n";
			$col ++;
		}

		$file_content .=  "<td class=\"elementCell\">
			<h4>$element[1]</h4>
			<ul>
				<li>No ".($ind + 1)."</li>
				<li>$element[2]</li>
				<li>$element[3]</li>
				<li>$element[4] electron</li>
			</ul>
		</td>\n";
		$col ++;
		if ($col == MAX_COLS)
		{
			$file_content .= "</tr>\n";
			$col = 0;
		}
	}
	// $file_content .=  "</tr>\n";
	$file_content .=  "</table>\n";
	$file_content .= "</body>\n";
	file_put_contents($output_file, $file_content);
}
