<?php
function delete_user($login){
	$tab = file('users/users');
	foreach ($tab as $key => $value){	
		$str = explode(';', $value);
		if ($str[0] == $login){
			unset($tab[$key]);
		}
	}
	file_put_contents('users/tmp', $tab);
	rename('users/tmp', 'users/users');
}
?>
