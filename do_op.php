#!/usr/bin/php
<?php
	if ($argc == 4){
		for ($i=1; $i < $argc; $i++)
			$str = $str.' '.$argv[$i];
		$new = str_replace("\t", ' ', str);
		$new = explode(' ', $str);
		$new3 = array_filter($new);
		
		foreach ($new3 as $key => $value) {
			$new2[] = $value;
		}
		$i = intval($new2[0]);
		$j = intval($new2[2]);
		switch ($new2[1]) {
			case '+':
				echo $i + $j."\n";
				break;
			case '-':
				echo $i - $j."\n";
				break;
			case '%':
				echo $i % $j."\n";
				break;
			case '*':
				echo $i * $j."\n";
				break;
			case '/':
				echo $i / $j."\n";
				break;
		}
	}
	else
		echo "Incorrect Parameters"."\n";
?>