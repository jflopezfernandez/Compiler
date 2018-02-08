#ifndef SRC_INCLUDES_RETVAL_H_
#ifndef SRC_INCLUDES_ARGS_H_
#define SRC_INCLUDES_ARGS_H_

#include "name.h"

char* factor();
char* term();
char* expression();
void statements();

extern char* newName();
extern void freeName(char* name);

#endif /** SRC_INCLUDES_ARGS_H_ */
#endif /** SRC_INCLUDES_RETVAL_H_ */