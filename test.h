#ifndef DTL_TEST_H
#define DTL_TEST_H

#include <stdio.h>

#define test(condition) \
fprintf(stderr, "%s: test '%s' ", __func__, #condition); \
if (condition) {fprintf(stderr, "passed.\n");} \
else {fprintf(stderr, "failed.\n");}

#endif

