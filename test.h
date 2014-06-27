#ifndef DTL_TEST_H
#define DTL_TEST_H

#include <stdio.h>

#define test(condition) \
if (condition) {fprintf(stderr, "PASSED: ");} \
else {fprintf(stderr, "FAILED: ");} \
fprintf(stderr, "%s: test '%s'\n", __func__, #condition);

#endif

