/* Implementation of the functions in project two */
#include "functions.h"

char *  removeDuplicates(char word[])
{	
	int i, j, k;
	int size = strlen(word);

	for(i = 0; i < size; i++)
	{
		for(j = i + 1; j < size; j++)
		{
			if(word[j] == word[i])
			{
				for(k = j; k < size; k++)
				{
					word[k] = word[k + 1];
				}
				size--;
				j--;	
			}
		}
	}		
	return word;
}

void initializeEncryptArray(char key[], char encrypt[])
{
	
	char* alphabet = "ZYXWVUTSRQPONMLKJIHGFEDCBA";
	char* temp = malloc(strlen(key) + 27);
	int i, j, count;

	strcpy(temp, key);
	strcat(temp, alphabet);
	removeDuplicates(temp);

	for(i = 0; i < MAXNUM; i++)
		encrypt[i] = temp[i];

	encrypt[MAXNUM] = '\0';
	free(temp);
}

void initializeDecryptArray(char encrypt[], char decrypt[])
{
	int i;
	for(i = 0; i < MAXNUM; i++)
		decrypt[encrypt[i] - 'A'] = i + 65;

	decrypt[MAXNUM] = '\0';
}

void processInput(char* inf, char* outf, char substitute[])
{

	FILE *fpin, *fpout;
	char ch;

	fpin = fopen(inf, "r");
	fpout = fopen(outf, "w");

	if(fpin == NULL)
	{
		printf("File could not be opened\n");
		exit(1);
	}
	while(fscanf(fpin, "%c", &ch) != EOF)
	{
		if(isalpha(ch))
			fprintf(fpout, "%c", substitute[ch - 'A']); 
		else
			fprintf(fpout, "%c", ch);
	}

	fclose(fpin);
	fclose(fpout);
}

