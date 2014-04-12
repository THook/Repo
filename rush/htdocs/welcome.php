<?php
include("functions/login_exists.php");
include("functions/register_user.php");
if (!$_POST)
	echo "?";
if (login_exists($_POST['login'])){
	echo "Sorry, login already taken\n";
	echo "<meta http-equiv\"refresh\" content=\"1\"; url=rush.local.42.fr8080/create_user.php\"\>";
}
else{
	register_user($_POST);
	echo "<a href=\"create_user.php\"></a>";
	echo "<meta http-equiv\"refresh\" content=\"1\"; url=rush.local.42.fr8080/index.php\"\>";
}
?>
