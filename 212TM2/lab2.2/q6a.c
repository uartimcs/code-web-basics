#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
  FILE* ptr;
  char * token;
  char line[256];
  int num[20][20];
  int key[3];
  int count[3] = {0, 0, 0};
  ptr = fopen("sample.txt","r");
  if (ptr == NULL)
  {
    perror("Error opening file");
    return(-1);
  }
  printf("Please enter 3 keys (separated by space) :");
  scanf("%d%d%d",&key[0],&key[1],&key[2]);


int i = 0;
while (fgets(line, 256, ptr)!= NULL)
{

token = strtok(line, " ");

int j = 0;
while (token != NULL)
{
num[i][j] = atoi(token);
if (num[i][j] == key[0])
count[0]++;
if (num[i][j] == key[1])
count[1]++;
if (num[i][j] == key[2])
count[2]++;
token = strtok(NULL, " ");
j++;
}

i++;
}
fclose(ptr);
for (int m = 0; m < 3; m++)
{
printf("The key '%d' is found %d times in the database\n",key[m],count[m]);}
  return 0;
}
