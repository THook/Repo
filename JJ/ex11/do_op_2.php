#!/usr/bin/php
<?php
	if ($argc == 2){
		$str = str_replace("\t", ' ', $argv[1]);
		$str = explode(' ', $str);
		$str = array_filter($str);
		foreach ($str as $key => $value) {
			if ($value != ' ') {
				$new_str = $new_str.$value;
			}
		}
		if (count($final_str = explode('*', $new_str)) == 2) {
			if (is_numeric($final_str[0]) && is_numeric($final_str[1])) {
				echo $final_str[0] * $final_str[1]."\n";
			}else
				echo "Syntax Error\n";
		}elseif (count($final_str = explode('/', $new_str)) == 2) {
			if (is_numeric($final_str[0]) && is_numeric($final_str[1])) {
				echo $final_str[0] / $final_str[1]."\n";
			}else
				echo "Syntax Error\n";
		}elseif (count($final_str = explode('+', $new_str)) == 2) {
			if (is_numeric($final_str[0]) && is_numeric($final_str[1])) {
				echo $final_str[0] + $final_str[1]."\n";
			}else
				echo "Syntax Error\n";
		}elseif (count($final_str = explode('-', $new_str)) == 2) {
			if (is_numeric($final_str[0]) && is_numeric($final_str[1])) {
				echo $final_str[0] - $final_str[1]."\n";
			}else
				echo "Syntax Error\n";
		}elseif (count($final_str = explode('%', $new_str)) == 2) {
			if (is_numeric($final_str[0]) && is_numeric($final_str[1])) {
				echo $final_str[0] % $final_str[1]."\n";
			}else
				echo "Syntax Error\n";
		}else
			echo "Syntax Error\n";
	}
	else
		echo "Incorrect Parameters\n";
?>