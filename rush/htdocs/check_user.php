#!/usr/bin/php
<?php
$ret = 1;
$user = "Hugo";
$password = "Bonjour";
$crypt = hash('whirlpool', $password);
$handle = fopen("users/users", 'r');
while (!feof($handle)){
	$act = fgets($handle, 1024);
	$tab = explode(";", $act);
	if ($tab[0] == $user){
		if ($tab[1] == $crypt)
			echo "OK!\n";
		else{
			echo "Wrong password or user\n";
			$ret = 2;
		}
	}
	if ($ret == 2)
		die();
}
?>
