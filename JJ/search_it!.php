#!/usr/bin/php
<?php
	if ($argc > 2){
		for ($i=2;$i < $argc;$i += 1){
			$str = NULL;
			$str = $str.' '.$argv[$i];
			$str = explode(':', trim($str));
			if (!$str[1] || $str[2]){
				echo "Syntax error\n";
				break;
			}
			$tab[] = $str[0];
			$tab1[] = $str[1];
		}
		foreach ($tab as $key => $value) {
			if ($value == $argv[1]){
				echo $tab1[$key]."\n";
				break;
			}
		}
	}
?>
