
################################################################################
#
#
#  						COMPILER IN C MAKEFILE
#
################################################################################


CC := gcc

CFLAGS := -std=c11 -Wall -Wextra -Wpedantic
CPPFLAGS := -I include
LFLAGS := 

vpath %.c src
vpath %.h include

SRCS := main.c
OBJS := $(patsubst %.c, %.o, $(SRCS))

PROGRAM := compiler.exe


$(PROGRAM): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) $(CPPFLAGS) -c  -o $@ $^

clean:
	rm -rf $(OBJS) $(PROGRAM)
