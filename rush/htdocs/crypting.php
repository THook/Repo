#!/usr/bin/php
<?php
$user = "Hugo";
$password = "Bonjour";
$type = 1;
$crypted = hash('whirlpool', $password);
$handle = fopen("users/users", 'a');
if ($type == 1)
	fwrite($handle, $user.";".$crypted.";read\n");
else
	fwrite($handle, $user.";".$crypted.";read&write\n");
fclose($handle);
?>
