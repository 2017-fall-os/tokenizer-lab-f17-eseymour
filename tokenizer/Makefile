CC = gcc
CFLAGS = -std=c99 -Wall -Werror -pedantic -Wno-unused-result ${BUILDFLAGS}
.PHONY: all
all:
	${MAKE} clean
	${MAKE} test
	${MAKE} clean
	${MAKE} release

.PHONY: release debug
release: BUILDFLAGS = -DNDEBUG -O3
debug: BUILDFLAGS = -DDEBUG -O0 -g
release debug: tokenizer

.PHONY: test
test: BUILDFLAGS = -DDEBUG -O0 -g
test: token_test
	./token_test

tokenizer: tokenizer.o mytok.o token.o
token_test: token_test.o mytok.o token.o

mytok.o: mytok.c token.h
token.o: token.c token.h
token_test.o: token_test.c token.h minunit.h
tokenizer.o: tokenizer.c token.h

.PHONY: clean
clean:
	rm -f *.o tokenizer token_test
