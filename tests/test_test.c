#include "../test.h"

void test_failing(void)
{
    test(1 == 0);
}

void test_passing(void)
{
    test(0 == 0);
}

int main(void)
{
    test_failing();
    test_passing();

    return 0;
}

