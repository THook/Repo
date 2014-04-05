#!/usr/bin/php
<?php
if ($argc > 1) {
	$new_str = explode(' ', $argv[1]);
	foreach ($new_str as $key => $value) {
		if ($value != '')
			$final_tab[] = $value;
	}
	$final_str = implode(' ', $final_tab);
	printf("%s", $final_str."\n");
}
?>
