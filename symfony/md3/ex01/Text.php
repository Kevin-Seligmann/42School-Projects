<?php

class Text {
	private $_arr;

	public function __construct($arr)
	{
		if (isset($arr))
			$this->_arr = $arr;
		else
			$this->_arr = [];
	}

	public function append($str){
		$this->_arr[] = $str;
	}

	public function readData(){
		$result = "";

		foreach ($this->_arr as $str)
			$result .= "<p>$str</p>\n";

		return $result;
	}
}
