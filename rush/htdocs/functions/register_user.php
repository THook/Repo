<?php
function register_user($infos){
$handle = fopen("users/users", 'a');
$crypt = hash('whirlpool', $infos[password]);
fwrite($handle, $infos[login].";".$crypt."read\n");
fclose($handle);
}
?>
