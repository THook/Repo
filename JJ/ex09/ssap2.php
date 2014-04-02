#!/usr/bin/php
<?php
	if ($argc > 1) {
		for ($i=1; $i < $argc; $i++)
			$str = $str.' '.$argv[$i];
		$new_str = explode(' ', $str);
		foreach ($new_str as $key => $value) {
			if (is_numeric($value)) {
				$num[] = $value;
			}elseif (ctype_alpha($value)) {
				$new_str_new[] = $value;
			}elseif ($value != "")
				$rest[] = $value;
		}
		if ($new_str_new){
			sort($new_str_new, SORT_FLAG_CASE|SORT_STRING);
			foreach ($new_str_new as $key => $value) {
				echo $value."\n";
			}
		}
		if ($num){
			sort($num, SORT_FLAG_CASE|SORT_STRING);
			foreach ($num as $key => $value) {
				echo $value."\n";
			}
		}
		if ($rest){
			sort($rest, SORT_FLAG_CASE|SORT_STRING);
			foreach ($rest as $key => $value) {
				echo $value."\n";
			}
		}
	}
?>