#ifndef MUNIT_H
#define MUNIT_H

#include <stdio.h>

#define xstr(s) str(s)
#define str(s) #s


/* A short unit testing framework I found online:
 * http://www.jera.com/techinfo/jtns/jtn002.html
 * I made a few modifications to print the line and file */

#define mu_assert(message, test) do { if (!(test)) \
                                return __FILE__"(" xstr(__LINE__) "): " \
                                  message; \
                              } while (0)

#define mu_run_test(test) do { char *message = test(); tests_run++; \
                                if (message) return message; } while (0)
extern int tests_run;

#endif // MUNIT_H
