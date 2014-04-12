<?php
function login_exists($login){
	$handle = fopen("users/users", 'r');
	while (!feof($handle)){
		$act = fgets($handle, 1024);
		$ret = explode(";", $act);
		if ($ret[0] == $login)
			return true;
	}
	return false;
}
?>
