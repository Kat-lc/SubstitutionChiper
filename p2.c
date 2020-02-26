#include "functions.h"

int main(int argc, char* argv[])
{
	char encrypt[MAXNUM];
	char decrypt[MAXNUM];
	char* key = argv[2];
	char* finName = argv[3];
	char* foutName = argv[4];

	initializeEncryptArray(key, encrypt);
	
	if(strcmp(argv[1], "e") == 0)
	{
		processInput(argv[3], argv[4], encrypt);
		
	}
	else if(strcmp(argv[1], "d") == 0)
	{
		initializeDecryptArray(encrypt, decrypt);
		processInput(argv[3], argv[4], decrypt);
	}
	else
	{
		printf("Error: Program doesn't know whether to encrypt or decrypt. Fix make file");
	}	

	return 0;
}
