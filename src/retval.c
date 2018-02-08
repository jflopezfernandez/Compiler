
/** Code Generation Using Return Values */

#include "retval.h"


void statements() {
	char *tempvar;
	
	while (!match(EOI)) {
		temporary = expression();
		
		if (match(SEMI)) {
			advance();
		} else {
			fprintf(stderr, "%d: Inserting missing semicolon\n", yylineno);
		}
		
		freeName(temporary);
	}
}

char* expression() {
	char *tempvar, *tempvar2;
	
	tempvar = term();
	
	while (match(PLUS)) {
		advance();
		temporary2 = term();
		
		printf("\t%s += %s\n", tempvar, tempvar2);
		
		freeName(tempvar2);
	}
	
	return tempvar;
}

char* term() {
	char *tempvar, *tempvar2;
	
	tempvar = factor();
	
	while (match(TIMES)) {
		advance();
		tempvar2 = factor();
		
		printf("\t%s *= %s\n", tempvar, tempvar2);
		
		freeName(tempvar2);
	}
	
	return tempvar;
}

char* factor() {
	char *tempvar;
	
	if (match(NUM_OR_ID)) {
		printf("\t%s = %0.*s\n", tempvar = newName(), yyleng, yytext);
		advance();
	} else if (match(LP)) {
		advance();
		tempvar = expression();
		
		if (match(RP)) {
			advance();
		} else {
			fprintf(stderr, "%d: Mismatched parenthesis\n", yylineno);
		}
	} else {
		fprintf(stderr, "%d: Number or identifier expected\n", yylineno);
	}
	
	return tempvar;
}
