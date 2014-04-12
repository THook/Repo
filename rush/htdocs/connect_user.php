<?php
include("functions/login_exists.php");
include("functions/incorrect_passwd.php");
include("functions/delete_user.php");
if ($_POST['submit'] == 'submit')
{
	if (!ctype_alpha($_POST['login']) || !ctype_alpha($_POST['password']))
		echo "Please enter an alphanumeric string\n";
	else if (!login_exists($_POST['login']) || incorrect_passwd($_POST)){
		echo "<script type=\"text/javascript\">alert(\"Incorrect login-password couple\");</script>";
	}
	else if (!incorrect_passwd($_POST) && $_POST['delete'] == 'yes'){
		delete_user($_POST['login']);
	//	header("Location: /index.php");
	}
	else
		header("Location: /index.php");
}
echo "<form action=\"connect_user.php\" method=\"post\">";
echo "Login: <input type=\"text\" name=\"login\">";
echo "<br />";
echo "Password: <input type=\"text\" name=\"password\">";
echo "<input type=\"submit\" name=\"submit\" value=\"submit\">";
echo "<br /><br />";
echo "<input type=\"radio\" name=\"delete\" value=\"yes\">Wanna delete your account ?";
echo "</form>"
?>
