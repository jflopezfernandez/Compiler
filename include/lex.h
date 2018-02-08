#ifndef SRC_INCLUDES_LEX_H_
#define SRC_INCLUDES_LEX_H_

#include "stddefs.h"

#define EOI 		0 	/** End Of Input 				*/
#define SEMI 		1 	/** ; 							*/ 
#define PLUS 		2 	/** + 							*/
#define TIMES 		3 	/** * 							*/
#define LP 			4 	/** ( 							*/
#define RP 			5 	/** ) 							*/
#define NUM_OR_ID 	6 	/** Decimal No or Identifier 	*/

#define MAXFIRST 	16
#define SYNCH 		SEMI

extern char **yytext;

extern int yyleng;
extern int yylineno;

void lex();

int match(int token);

void advance();

int legal_lookahead(int first_arg);


#endif /** SRC_INCLUDES_LEX_H_ */
