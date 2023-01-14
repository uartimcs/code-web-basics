<?php

	echo "<H1><center>Welcome to the restricted area</center></H1><BR>";
	echo "<font size=5>Only authorized users can access the contents here.<p>";
	$user=apache_getenv("REMOTE_user"); 
	echo "<font color=blue><b> You are <font color=red>&quot;$user&quot;</font>.</b></font><p>";
	echo "Nice to meet you! Enjoy your visit.<p></font>";
?>
