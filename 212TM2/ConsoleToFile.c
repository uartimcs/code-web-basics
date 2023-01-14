#include <stdio.h>  // Error 1: missing <> for header file stdio.h
#include <stdlib.h> // Error 1: missing <> for header file stdlib.h
void flush_input_buffer(); // a warning only. not an error.
int main(void)
{
FILE *outputFile;
char file_name[50]; // Error 2: array size must be predefined in C
int ch;

printf("This program saves your console input to an output file.\n");
printf("Enter the name of the output file: ");
scanf("%s", file_name);
flush_input_buffer();

if ((outputFile = fopen(file_name, "w")) == NULL) {
// Error 3 : miss a () to check success of open file
printf("Cannot open %s for writing.\n", file_name);
return EXIT_FAILURE;
}

printf("Enter your input (Press Ctrl-D when done) ...\n");

while ((ch = getc(stdin)) != EOF) { // Error 4 : redundant ; after while
putc(ch, outputFile);
}

fclose(outputFile);

printf("===== Ctrl-D pressed ===== \n");
printf("Input saved to file %s\n", file_name);
// Error 5 : file_name store the name of file, not outputFile pointer.

return EXIT_SUCCESS;
}

void flush_input_buffer() {
while (getchar() != '\n') {
continue;
}
}

