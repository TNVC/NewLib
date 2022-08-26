#include <stdio.h>
#include <assert.h>
#include "newstdio.h"

int newputs(const char *str)
{
    assert(str != nullptr);

    for (const char *ch = str; *ch; ++ch)
        if (putchar(*ch) == EOF)
            return EOF;

    if (putchar('\n') == EOF)
        return EOF;

    return 1;
}
