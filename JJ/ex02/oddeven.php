#!/usr/bin/php
<?php
	echo "Entrez un nombre: ";
	while (($num = fgets(STDIN)) != NULL) {
		$num = substr($num, 0, -1);
		if (ctype_digit($num)) {
			if (($num % 2) == 0) {
				echo "Le chiffre ".$num." est Pair\n";
			}
			else
				echo "Le chiffre ".$num." est Impair\n";
		}
		else {
			echo "'".$num."' n'est pas un chiffre\n";
		}
		echo "Entrez un nombre: ";
	}
	echo "^D\n";
?>
