/** @file lex.c
 *  
 *  @brief Main lexer and parser implementation code
 *
 */

#include "lex.h"

static int lookahead = -1;

char *yytext = "";
int yyleng = 0;
int yylineno = 0;

void lex() {
	static char inputBuffer[128];
	char *current;
	
	current = yytext + yyleng;
	
	while (TRUE) {
		while (!*current) {
			/** Get new lines, skipping any leading white space on the line, 
			 *  until a nonblank line is found */
			
			current = inputBuffer;
			
			// TODO: Remove gets() function call
			if (!gets(inputBuffer)) {
				*current = '\0';
				
				return EOI;
			}
			
			++yylineno;
			
			while (isspace(*current)) {
				++current;
			}
		}
		
		for ( ; *current; ++current) {
			/** Get next token */
			
			yytext = current;
			yyleng = 1;
			
			switch (*current) {
				case EOF: return EOI;
				case ';': return SEMI;
				case '+': return PLUS;
				case '*': return TIMES;
				case '(': return LP;
				case ')': return RP;
				
				case '\n':
				case '\t': 
				case ' ' : break;
				
				default: {
					if (isalnum(*current)) {
						fprintf(stderr, "Ignoring illegal input <%c>\n", *current);
					} else {
						while (isalnum(*current)) {
							++current;
						}
						
						yyleng = current - yytext;
						
						return NUM_OR_ID;
					}
				} break;
			}
		}
	}
}

int match(int token) {
	if (lookahead == -1) {
		lookahead = lex();
	}
	
	return token == lookahead;
}

void advance() {
	lookahead = lex();
}

void statements() {
	while (!match(EOI)) {
		expression();
		
		if (match(SEMI)) {
			advance();
		} else {
			fprintf(stderr, "%d: Inserting missing semicolon\n", yylineno);
		}
	}
}

void expression() {
	/** expression  -> term expression'
	 *  expression' -> PLUS term expression' | EPSILON
	 */
	
	if (!legal_lookahead(NUM_OR_ID, LP, 0)) {
		return;
	}
	
	term();
	
	while (match(PLUS)) {
		advance();
		term();
	}
}

void term() {
	if (!legal_lookahead(NUM_OR_ID, LP, 0)) {
		return;
	}
	
	factor();
	
	while (match(TIMES)) {
		advance();
		factor();
	}
}

/** @fn void factor()
 *
 */

void factor() {
	if (!legal_lookahead(NUM_OR_ID, LP, 0)) {
		return;
	}
	
	if (match(NUM_OR_ID)) {
		advance();
	} else if (match(LP)) {
		advance();
		expression();
		
		if (match(RP)) {
			advance();
		} else {
			fprintf(stderr, "%d: Mismatched parenthesis\n", yylineno);
		}
	} else {
		fprintf(stderr, "%d: Number or identifier expected\n");
	}
}

/** @fn int legal_lookahead(int firstArg)
 *
 *  @param firstArg Zero-terminated variable list of int-macro tokens that are
 *  allowed to come next in the input
 *
 *  Simple error detection and recovery. Arguments are a 0-terminated list of
 *  those tokens that can legitimately come next in the input. If the list is
 *  empty, the end of file must come next. Print an error message if
 *  necessary. Error recovery is performed by discarding all input symbols
 *  until one that's in the input list is found.
 *
 * Return true if there's no error or if we recovered from the error,
 * false if we can't recover.
 *
 */

int legal_lookahead(int first_arg) {
	va_list args;
	
	int tok;
	int lookaheads[MAXFIRST], *p = lookaheads, *current;
	int error_printed = 0;
	int rval = 0;
	
	va_start(args, first_arg);
	
	if (!first_arg) {
		if (match(EOI)) {
			rval = EXIT_FAILURE;
		} else {
			// TODO: Add something for an else case??
		}
	} else {
		*p++ = first_arg;
	}
}


