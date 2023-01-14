<?php
# File: fibon-2.php
# Lab 2.4 - Program 2 - Fibonacci Numbers in PHP
# This program calculates the first MAX_N Fibonacci numbers and prints them out
#
define ("PROGRAM_NAME","Lab 2.4 - Program 2 - Fibonacci Numbers (PHP)");
define ("MAX_N",20);
$fibonacci = array(0,1);
$n = 1;
print PROGRAM_NAME."\n";
print "The first ".MAX_N." Fibonacci numbers are:\n";
while (sizeof($fibonacci) < MAX_N) {
$n = $fibonacci[sizeof($fibonacci) - 1] + $fibonacci[sizeof($fibonacci) - 2];
array_push($fibonacci, $n);
}
foreach ($fibonacci as $no) {
print $no.", ";
}
print "...\n";
exit(0);
?>
