#!/usr/bin/php
<?php
	function ft_split($string){
		$array = explode(' ', $string);
		sort($array);
		return (array_filter($array));
	}
?>
