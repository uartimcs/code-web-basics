/*
File: fibonacci4.cgi.c
Lab 2.2 - Q5 Program 4 - Fibonacci Numbers (CIA version)
This program calculates multiple Fibonacci numbers from multiple field inputs.
In addition, it keeps a counter of how many times this program has been accessed.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRAM_NAME "Lab 2.2 - Q5 Program 4 - Fibonacci Numbers (with User Input and Counter)"
#define COUNTER_FILE "counter4.txt"

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

int getInput(char *str)
{
    char phrase[50];
    strcpy(phrase,str);
    return atoi(phrase + 12);
}

void fibon(int num_input)
{
int n = 0;
unsigned long long first_term = 0;
unsigned long long second_term = 1;
unsigned long long count;
    printf("The first %d Fibonacci Numbers are: \n",num_input);
    printf("<br /> \n");
    while (n < num_input)
    {
        if (n == 0)
        {
            count = 0;
        }
        else if (n == 1)
        {
            count = 1;
        }
        else
        {
            count = second_term + first_term;
        }
        printf("%llu\t",count);
        n++;
        first_term = second_term;
        second_term = count;
    }
printf("...\n");
printf("<p></p>");
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
  int  data_len;
  char * token;
  char sub_string[10][25];
  char data_string[500];
  data_len = atoi(getenv("CONTENT_LENGTH"));
  fread(data_string, 1, data_len, stdin);
  data_string[data_len] = '\0';
  int i = 0;
 
printHeader();
 printf("<h2>%s</h2> \n", PROGRAM_NAME);
  token = strtok(data_string,"&");

  while (token != NULL)
  {
      strcpy(sub_string[i], token);
      i++;
      token = strtok(NULL, "&");
  }

  for (int j = 0; j < i; j++)
  {
      int m = getInput(sub_string[j]);
      fibon(m);
  }

 printFooter();
 return 0;
}

