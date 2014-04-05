#!/usr/bin/php
<?php
	function ft_split($string){
		$array = array_filter(explode(' ', $string));
		foreach ($array as $key => $value)
			$ret[] = $value;
		return ($ret);
	}
?>
