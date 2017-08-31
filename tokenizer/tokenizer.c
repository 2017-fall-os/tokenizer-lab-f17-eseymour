#include <stdlib.h>
#include <unistd.h>

#include "token.h"

#define BUFLEN 100

char *quitTok[] = {"quit", (char *) 0};

static char buffer[BUFLEN];

int main(void) {
  write(STDOUT_FILENO, "Tokenizer Lab by Edward Seymour\n", 32);
  write(STDOUT_FILENO, "Type \"quit\" to quit program.\n", 29);
  for (int quit = 0; !quit;) {
    write(STDOUT_FILENO, "$ ", 2);
    ssize_t numChars = read(STDIN_FILENO, buffer, BUFLEN - 1);
    buffer[numChars - 1] = '\0';

    char **tokens = mytok(buffer, ' ');
    for (char **tokensCursor = tokens; *tokensCursor != 0; tokensCursor++) {
      write(STDOUT_FILENO, *tokensCursor, toklen(*tokensCursor, ' '));
      write(STDOUT_FILENO, "\n", 1);
    }

    quit = tokcmp(quitTok, tokens) == 0;

    freetok(tokens);
  }

  return 0;
}
