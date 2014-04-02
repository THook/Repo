#!/usr/bin/php
<?php
if ($argc > 2){
	$ret = 0;
	for ($i=2;$i < $argc;$i++){
		$str = NULL;
		$str = $str.' '.$argv[$i];
		$str = explode(':', trim($str), 2);
		if (!$str[1]){
			echo "Syntax error\n";
			$ret = 1;
			break;
		}
		$tab[$str[0]] = $str[1];
	}
	if ($ret == 0)
		echo $tab[$argv[1]]."\n";
}
?>
