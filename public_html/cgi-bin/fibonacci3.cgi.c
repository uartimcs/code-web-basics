/*
File: fibonacci3.cgi.c
Lab 2.2 - Program 3 - Fibonacci Numbers (CIA version)
This program calculates the first n Fibonacci numbers (where n is submitted via an
input form) and prints them to the browser output. In addition, it keeps a counter
of how many times this program has been accessed.
*/
#include <stdio.h>

#define PROGRAM_NAME "Lab 2.2 - Program 3 - Fibonacci Numbers (with User Input and Counter)"
#define COUNTER_FILE "counter.txt"

/* This function increments the counter and returns the new counter value */
int incrementCounter(void) {
int counter = 0;

/* Opens the counter file if it exists; otherwise creates the file for read/write */
FILE* fp = fopen(COUNTER_FILE, "r+");
if (!fp) {
fp = fopen(COUNTER_FILE, "w+");
}

/* Reads the current counter value and increment it. If the counter file is new
or the counter value is invalid, the counter value of 0 is used. */
fscanf(fp, "%d", &counter);
counter++;

/* Overwrites the current counter value with the incremented one */
fseek(fp, 0, SEEK_SET);
fprintf(fp, "%d", counter);

/* Remember to close the file before exiting the function! */
fclose(fp);
return counter;
}

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
 printf("<h4>This program has been accessed ");
 printf("<font color='steelblue'><b>%d</b></font> times.</h4> \n", incrementCounter());
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
