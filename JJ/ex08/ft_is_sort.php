<?php
	function ft_is_sort($tab){
		$tab_sort = $tab;
		sort($tab_sort);
		$i = 0;
		foreach ($tab as $key => $value) {
			if ($value != $tab_sort[$i++]) {
				return false;
			}
		}
		return true;
	}
?>
