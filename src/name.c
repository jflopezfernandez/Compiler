
#include "name.h"


char *Names[] = { "t0", "t1", "t2", "t3", "t4", "t5", "t6", "t7" };
char **Namep = Names;


char *newName() {
	if (Namep >= &Names[sizeof(Names)/sizeof(*Names)]) {
		fprintf(stderr, "%d: Expression too complex\n", yylineno);
		
		exit(EXIT_FAILURE);
	}
	
	return (*Namep++);
}

freeName(char *s) {
	if (Namep > Names) {
		*--Namep = s;
	} else {
		fprintf(stderr, "%d: (Internal Error) Name stack underflow\n");
	}
}