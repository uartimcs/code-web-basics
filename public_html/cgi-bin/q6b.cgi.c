#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define PROGRAM_NAME "Program to Check number of occurence of three numbers."
#define COUNTER_FILE "counter6b.txt"
#define	READ_FILE "sample.txt"

int incrementCounter(void)
{
  int counter = 0;
  FILE* fp = fopen(COUNTER_FILE,"r+");
  if (!fp){
    fp = fopen(COUNTER_FILE,"w+");
  }

  fscanf(fp, "%d", &counter);
  counter++;			
  fseek(fp, 0, SEEK_SET);	
  fprintf(fp, "%d", counter);	
  fclose(fp);			
  return counter;		
}

int getInput(char *str)
{
    char phrase[30];		
    strcpy(phrase,str);		
    return atoi(phrase + 12);	
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
  printf("<font color = 'steelblue'><b>%d</b></font> times.</h4> \n", incrementCounter());
  printf("</body> \n");
  printf("</html> \n");
}

int main()
{

char sub_string[10][25];

char * token;
int data_len;

FILE *fileptr;
char line[100];
int num[15][10];	
int counter[3] = {0, 0, 0};
int key[3] = {0, 0, 0};

data_len = atoi(getenv("CONTENT_LENGTH"));
char data_string[data_len];
fread(data_string, 1, data_len, stdin);
data_string[data_len] = '\0';

printHeader();
token = strtok(data_string,"&");
	
int string_cut = 0;			
while (token != NULL)
{
strcpy(sub_string[string_cut],token);
token = strtok(NULL, "&");	
string_cut++;			
}

key[0] = getInput(sub_string[0]);
key[1] = getInput(sub_string[1]);
key[2] = getInput(sub_string[2]);

fileptr = fopen(READ_FILE,"r");	

if (fileptr == NULL)
  {
    perror("Error opening file");
    return(-1);
  }

int i = 0;
while (fgets(line, 256, fileptr)!= NULL)
{

token = strtok(line, " ");

int j = 0;
while (token != NULL)
{
num[i][j] = atoi(token);
if (num[i][j] == key[0])
counter[0]++;
if (num[i][j] == key[1])
counter[1]++;
if (num[i][j] == key[2])
counter[2]++;
token = strtok(NULL, " ");
j++;
}

i++;
}
fclose(fileptr);
printf("<p></p>");

for (int w = 0; w < 3; w++)
{
printf("<p></p>");
printf("The key '%d' is found %d times in the database\n",key[w],counter[w]);
}
printf("<p></p>");
printFooter();
printf("The document link is <a href=sample.txt>here</a>.\n");

return 0;
}
