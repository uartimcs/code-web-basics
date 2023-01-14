<!--
# File: fibon-3.php
# Lab 2.4 - Program 3 - Fibonacci Numbers in PHP
# This program calculates the first MAX_N Fibonacci numbers and prints them out
-->
<H3>Lab 2.4 - <font color=blue>Program 3</font> - Fibonacci Numbers (PHP)<H3>
<?php
define ("MAX_N",20);
$fibonacci = array(0,1);
$n = 1;
?>
<p>The first <? print MAX_N ?> Fibonacci numbers are:</p>
<? while (sizeof($fibonacci) < MAX_N) {
$n = $fibonacci[sizeof($fibonacci) - 1] + $fibonacci[sizeof($fibonacci) - 2];
array_push($fibonacci, $n);
}
foreach ($fibonacci as $no) {
print $no.", ";
}
?>
...</p>
