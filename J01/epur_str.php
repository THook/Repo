#!/usr/bin/php
<?php
if ($argc > 1) {
	$new_str = preg_split('/[\s ]+/', $argv[1], -1, PREG_SPLIT_NO_EMPTY);
	$final_str = implode(' ', $new_str);
	printf("%s", $final_str);
}
?>