<?php
$tab = file('users/boutique');
if (!$_GET || $_GET['disp'] == 1){
	foreach ($tab as $value){
		$str = explode(';', $value);
		echo "Produit:\t".$str[1]." prix:\t".$str[2].".<br />";
	}
}
else if ($_GET['disp'] == 2){
	foreach ($tab as $value){
		$str = explode(';', $value);
		if ($str[4] == '2')
			echo "Produit: ".$str[1]." prix: ".$str[2].".<br />";
	}
}
else if ($_GET['disp'] == 3){
	foreach ($tab as $value){
		$str = explode(';', $value);
		if ($str[5] == "3\n")
			echo "Produit:\t".$str[1]." prix:\t".$str[2].".<br />";
	}
}
echo "<br /><br />";
echo "<form action=\"boutique.php\" method=\"get\">";
echo "<input type=\"radio\" name=\"disp\" value=\"1\">Display everything <br />";
echo "<input type=\"radio\" name=\"disp\" value=\"2\">Display coloured screws <br />";
echo "<input type=\"radio\" name=\"disp\" value=\"3\">Display rare or essential items <br />";
echo "<input type=\"submit\" name=\"submit\" value=\"display\">";
echo "</form>"
?>
