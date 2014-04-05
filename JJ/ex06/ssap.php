#!/usr/bin/php
<?php
	if ($argc > 1) {
		for ($i=1; $i < $argc; $i++)
			$str = $str.' '.$argv[$i];
		$new_str = explode(' ', $str);
		foreach ($new_str as $key => $value) {
			if ($value != '') {
				$final_tab[] = $value;
			}
		}
		sort($final_tab);
		foreach ($final_tab as $key => $value) {
			echo $value."\n";
		}
	}
?>
