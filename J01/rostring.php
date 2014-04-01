#!/usr/bin/php
<?php
	if ($argc > 1) {
		$new_str = preg_split('/[\s ]+/', $argv[1], -1, PREG_SPLIT_NO_EMPTY);
		$new_str[] = $new_str[0];
		unset($new_str[0]);
		echo implode(' ', $new_str)."\n";
	}
?>