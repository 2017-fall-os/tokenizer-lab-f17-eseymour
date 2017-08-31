#include <stdio.h>
#include <string.h>

#include "minunit.h"
#include "token.h"

int  tests_run = 0;

char delim = ' ';

#define DARWIN "Hello my dog's name is Darwin."
#define HW_SPACE "     Hello   World!    "
#define EMPTY ""
#define SPACES "          "
#define HW_NOSPACE " HelloWorld"

char *emptyTok[] = {(char*) 0};
char *darwinTok[] = {"Hello", "my", "dog's", "name", "is", "Darwin.", (char*) 0};
char *hwSpaceTok[] = {"Hello", "World!", (char *) 0};
char *hwNoSpaceTok[] = {"HelloWorld", (char *) 0};

char * numtok_result() {
  #define MESSAGE "size_t numtok(char const *, char) returned value different from expected"

  mu_assert(MESSAGE, numtok(DARWIN, delim) == 6);
  mu_assert(MESSAGE, numtok(HW_SPACE, delim) == 2);
  mu_assert(MESSAGE, numtok(EMPTY, delim) == 0);
  mu_assert(MESSAGE, numtok(SPACES, delim) == 0);
  mu_assert(MESSAGE, numtok(HW_NOSPACE, delim) == 1);

  return 0;
}

char * toklen_result() {
  #undef MESSAGE
  #define MESSAGE "size_t toklen(const char *, char) returned a value different than expected"

  mu_assert(MESSAGE, toklen(DARWIN, delim) == 5);
  mu_assert(MESSAGE, toklen(DARWIN + 6, delim) == 2);
  mu_assert(MESSAGE, toklen(DARWIN + 9, delim) == 5);
  mu_assert(MESSAGE, toklen(DARWIN + 15, delim) == 4);
  mu_assert(MESSAGE, toklen(DARWIN + 20, delim) == 2);
  mu_assert(MESSAGE, toklen(DARWIN + 23, delim) == 7);
  mu_assert(MESSAGE, toklen(HW_SPACE + 5, delim) == 5);
  mu_assert(MESSAGE, toklen(HW_SPACE + 13, delim) == 6);
  mu_assert(MESSAGE, toklen(HW_NOSPACE + 1, delim) == 10);

  return 0;
}

char * tokcpy_result() {
  #undef MESSAGE
  #define MESSAGE "char * tokcpy(char *, const char *, char) returned a value different than expected"

  char buf[100];

  mu_assert(MESSAGE, strcmp(tokcpy(buf, DARWIN, delim), "Hello") == 0);
  mu_assert(MESSAGE, strcmp(tokcpy(buf, DARWIN + 6, delim), "my") == 0);
  mu_assert(MESSAGE, strcmp(tokcpy(buf, DARWIN + 9, delim), "dog's") == 0);
  mu_assert(MESSAGE, strcmp(tokcpy(buf, DARWIN + 15, delim), "name") == 0);
  mu_assert(MESSAGE, strcmp(tokcpy(buf, DARWIN + 20, delim), "is") == 0);
  mu_assert(MESSAGE, strcmp(tokcpy(buf, DARWIN + 23, delim), "Darwin.") == 0);
  mu_assert(MESSAGE, strcmp(tokcpy(buf, HW_SPACE + 5, delim), "Hello") == 0);
  mu_assert(MESSAGE, strcmp(tokcpy(buf, HW_SPACE + 13, delim), "World!") == 0);
  mu_assert(MESSAGE, strcmp(tokcpy(buf, HW_NOSPACE + 1, delim), "HelloWorld") == 0);

  return 0;
}

char * tokcmp_result() {
  #undef MESSAGE
  #define MESSAGE "int tokcmp(const char **, const char **) returned a value different than expected"

  // Compare to self
  mu_assert(MESSAGE, tokcmp(emptyTok, emptyTok) == 0);
  mu_assert(MESSAGE, tokcmp(darwinTok, darwinTok) == 0);
  mu_assert(MESSAGE, tokcmp(hwSpaceTok, hwSpaceTok) == 0);
  mu_assert(MESSAGE, tokcmp(hwNoSpaceTok, hwNoSpaceTok) == 0);

  // Compare to empty
  mu_assert(MESSAGE, tokcmp(emptyTok, darwinTok) < 0);
  mu_assert(MESSAGE, tokcmp(darwinTok, emptyTok) > 0);
  mu_assert(MESSAGE, tokcmp(emptyTok, hwSpaceTok) < 0);
  mu_assert(MESSAGE, tokcmp(hwSpaceTok, emptyTok) > 0);

  // Other comparisons
  mu_assert(MESSAGE, tokcmp(darwinTok, hwSpaceTok) > 0);
  mu_assert(MESSAGE, tokcmp(darwinTok, hwNoSpaceTok) < 0);
  mu_assert(MESSAGE, tokcmp(hwSpaceTok, hwNoSpaceTok) < 0);

  return 0;
}

char * mytok_result() {
  #undef MESSAGE
  #define MESSAGE "char ** mytok(const char *, char) returned a value different than expected"

  char **tokens;

  tokens =  mytok(DARWIN, delim);
  mu_assert(MESSAGE, tokcmp(darwinTok, tokens) == 0);
  freetok(tokens);

  tokens =  mytok(HW_SPACE, delim);
  mu_assert(MESSAGE, tokcmp(hwSpaceTok, tokens) == 0);
  freetok(tokens);

  tokens =  mytok(EMPTY, delim);
  mu_assert(MESSAGE, tokcmp(emptyTok, tokens) == 0);
  freetok(tokens);

  tokens =  mytok(SPACES, delim);
  mu_assert(MESSAGE, tokcmp(emptyTok, tokens) == 0);
  freetok(tokens);

  tokens =  mytok(HW_NOSPACE, delim);
  mu_assert(MESSAGE, tokcmp(hwNoSpaceTok, tokens) == 0);
  freetok(tokens);

  return 0;
}

char * all_tests() {
  mu_run_test(numtok_result);
  mu_run_test(toklen_result);
  mu_run_test(tokcpy_result);
  mu_run_test(tokcmp_result);
  mu_run_test(mytok_result);
  return 0;
}

int main(void) {
  char *result = all_tests();
  if (result != 0) {
    printf("Test failed: %s\n", result);
  }
  else {
    printf("All tests passed\n");
  }

  printf("Tests run: %d\n", tests_run);

  return result != 0;
}
