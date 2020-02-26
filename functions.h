/* Defining the functions and preprocessor directives for project two */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

#define MAXNUM 26

/* Removes duplicate character in the array 'word'and returns the resulting string */
char * removeDuplicates(char word[]);

/* Initializes the encrypt array with appropriate cipher letters according to key */
void initializeEncryptArray(char key[], char encrypt[]);

void initializeDecryptArray(char encrypt[], char decrypt[]);

/* Passes the encrypt / decrypt arrays to substitute. Processes data from input, writes to output */
void processInput(char* inf, char * outf, char substitute[]);
