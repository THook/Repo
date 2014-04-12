<?php
function incorrect_passwd($var){
	$handle = fopen("users/users", 'r');
	while (!feof($handle)){
		$act = fgets($handle, 1024);
		$ret = explode(";", $act);
		if ($ret[0] == $var['login']){
			if ($var['passwd'] == hash('whirlpool', $ret[1]))
				return true;
			else
				return false;
		}
	}
return false;
}
?>
