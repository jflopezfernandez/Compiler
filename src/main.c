
/** ****************************************************************************
 *
 *  						COMPILER IN C
 *
 *  ***************************************************************************/
 
#include "stddefs.h"
#include "lex.h"
#include "retval.h"

void declaration();
void type();


int main(int argc, char *argv[])
{
	/** Make sure a filename was supplied */
	if (argc == 1) {
		fprintf(stderr, "[ERROR]: Not enough arguments...\n");
		
		exit(EXIT_FAILURE);
	}
	
	/** Open the given file */
	FILE* inputFile = fopen(argv[1], "r");
	
	if (inputFile == NULL) {
		fprintf(stderr, "[ERROR]: Unable to open file...\n");
		
		exit(EXIT_FAILURE);
	}
	
	// TODO: Process file here
	char c;
	
	while ((c = fgetc(inputFile)) != EOF) {
		printf("%c", c);
	}
	
	/** Close the file stream */
	fclose(inputFile);
}


void type() {
	
}