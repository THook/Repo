#!/usr/bin/php
<?php
function ft_split($string){
	$array = array_filter(explode(' ', $string));
	foreach ($array as $key => $value)
		$ret[] = $value;
	return ($ret);
}

if ($argc > 1){
	$alpha = array();
	$num = array();
	$other = array();
	for ($i=1; $i < $argc; $i++)
	{
		$array = ft_split($argv[$i]);
		foreach ($array as $elem)
		{
			if (ctype_alpha ($elem[0]))
				$alpha[] = $elem;
			else if (is_numeric($elem[0]))
				$num[] = $elem;
			else
				$other[] = $elem;
		}
	}
	natcasesort($alpha);
	usort($num, "strcmp");
	sort($other);
	foreach($alpha as $elem)
		echo $elem."\n";
	foreach($num as $elem)
		echo $elem."\n";
	foreach($other as $elem)
		echo $elem."\n";
}
?>
