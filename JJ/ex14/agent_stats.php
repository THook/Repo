#!/usr/bin/php
<?php
	if ($argc == 2)
	{
		while (($buffer = fgets(STDIN)) != NULL)
		{
			$tab = explode(";", $buffer);
			if (!$tab[3] || $tab[4])
				echo "Error\n";
			
			}
		}
	}
?>
