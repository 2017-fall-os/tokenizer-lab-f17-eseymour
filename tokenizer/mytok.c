#include "token.h"

#include <assert.h> // for assert
#include <stdlib.h> // for malloc

/* Tokenizes the str delimited by delim. Returns a zero terminated array
 * of token strings. */
char ** mytok(const char *str, char delim) {
  // First pass: calculate the number of tokens.
  size_t numTokens = numtok(str, delim);

  char **tokens = (char **)calloc(numTokens + 1, sizeof(char *));

  // Second pass: add each token to tokens.
  for (int i = 0; i < numTokens; ++i) {
    // Find start of token
    for (; *str == delim; ++str);

    size_t tokenLength = toklen(str, delim);
    char *token = (char *)calloc(tokenLength + 1, 1);
    tokcpy(token, str, delim);

    tokens[i] = token;

    // Jump one element past end of token
    str += tokenLength;
  }

  // No tokens should be left
  #ifndef NDEBUG
  // Skip past any remaining delimiters
  for (; *str == delim; ++str);

  assert(*str == '\0');
  #endif // NDEBUG

  return tokens;
}
