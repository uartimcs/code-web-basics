/*
 File: fibonacci.cgi.c
 Lab 2.2 - Program 1 - Fibonacci Numbers (CIA version)
 This program calculates the first MAX_N Fibonacci numbers and prints them to the
 browser output.
*/
#include <stdio.h>

#define PROGRAM_NAME "Lab 2.2 - Program 1 - Fibonacci Numbers"
#define MAX_N 20

void printHeader(void) {
 printf("Content-type: text/html\n\n");
 printf("<html> \n");
 printf("<head> \n");
 printf("<title>%s</title> \n", PROGRAM_NAME);
 printf("</head> \n");
 printf("<body style='padding: 25px;'> \n");
}

void printFooter(void) {
 printf("</body> \n");
 printf("</html> \n");
}

int main() {
 int n = 0;
 int last1 = 0;
 int last2 = 1;
 int current;

 printHeader();
 printf("<h2>%s</h2> \n", PROGRAM_NAME);
 printf("The first %d Fibonacci numbers are: \n", MAX_N);
 printf("<br /> \n");

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
 printFooter();
 return 0;
}
