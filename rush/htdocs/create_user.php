<?php
include("functions/login_exists.php");
include("functions/register_user.php");
if ($_POST['submit'] == "submit")
{
	if (!ctype_alpha($_POST['login']) || !ctype_alpha($_POST['password']))
		echo "Please enter an alphanumeric string\n";
	if (login_exists($_POST['login'])){
		echo "<script type=\"text/javascript\">alert(\"Login already exists\");</script>";
	}
	else{
		register_user($_POST);
		header("Location: /index.php");
	}
}
echo "<form action=\"create_user.php\" method=\"post\">";
echo "Login: <input type=\"text\" name=\"login\">";
echo "<br />";
echo "Password: <input type=\"text\" name=\"password\">";
echo "<input type=\"submit\" name=\"submit\" value=\"submit\">";
echo "</form>"
?>
