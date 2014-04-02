#!/usr/bin/php
<?php
	function ft_split($string){
		$array = explode(' ', $string);
		print_r(array_reverse($array));
	}
?>
