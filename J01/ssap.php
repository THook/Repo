#!/usr/bin/php
<?php
	if ($argc > 1) {
		for ($i=1; $i < $argc; $i++)
			$str = $str.' '.$argv[$i];
		$new_str = preg_split('/[\s ]+/', $str, -1, PREG_SPLIT_NO_EMPTY);
		sort($new_str);
		foreach ($new_str as $key => $value) {
			echo $value."\n";
		}
	}
?>
