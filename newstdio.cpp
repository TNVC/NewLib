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

char *newfgets(char *str, int n, FILE *stream)
{
    assert(str    != nullptr);
    assert(stream != nullptr);
    assert(n > 0);

    int ch = 0;
    int  i = 0;

    for ( ; ch != '\n' && ch != EOF && i < n - 1; ++i)
    {
        ch = getc(stream);
        str[i] = (char) ch;
    }

    if (ch == EOF)
        return nullptr;

    str[i] = '\0';

    return str;
}
