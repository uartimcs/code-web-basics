/*
 File: fibonacci.c
 Lab 2.2 - Program 1 - Fibonacci Numbers (Console version)
 This program calculates the first MAX_N Fibonacci numbers and prints them to the
 standard output (console).
*/
#include <stdio.h>

#define PROGRAM_NAME "Lab 2.2 - Program 1 - Fibonacci Numbers"
#define MAX_N 20

int main() {
 int n = 0;
 int last1 = 0;
 int last2 = 1;
 int current;

 printf("%s \n", PROGRAM_NAME);
 printf("The first %d Fibonacci numbers are:\n", MAX_N);

 while (n < MAX_N) {
 if (n == 0) {
 current = 0;
 } else if (n == 1) {
 current = 1;
 } else {
 current = last2 + last1;
 }
 printf("%d, ", current);
 last1 = last2;
 last2 = current;
 n++;
 }

 printf("...\n");
 return 0;
}
