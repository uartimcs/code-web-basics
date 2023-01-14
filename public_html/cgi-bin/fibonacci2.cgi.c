/*
File: fibonacci2.cgi.c
Lab 2.2 - Program 2 - Fibonacci Numbers (CIA version)
This program calculates the first n Fibonacci numbers (where n is submitted via an
input form) and prints them to the browser output.
*/
#include <stdio.h>

#define PROGRAM_NAME "Lab 2.2 - Program 2 - Fibonacci Numbers (with User Input)"

/* We know we have only one input field "max_n". */
int getInput(void) {
 char input[9];
 fgets(input, 9, stdin);
 return atoi(input + 6);
 }

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
 int max_n = getInput();
 
printHeader();
 printf("<h2>%s</h2> \n", PROGRAM_NAME);
 printf("The first %d Fibonacci numbers are: \n", max_n);
 printf("<br /> \n");

 while (n < max_n) {
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

