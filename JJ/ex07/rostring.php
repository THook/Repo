#!/usr/bin/php
<?php
	if ($argc > 1) {
		$str = $str.' '.$argv[1];
		$new_str = explode(' ', $str);
		foreach ($new_str as $key => $value)
			if ($value != '')
				$final_tab[] = $value;
		$final_tab[] = $final_tab[0];
		unset($final_tab[0]);
		echo implode(' ', $final_tab)."\n";
	}
?>
