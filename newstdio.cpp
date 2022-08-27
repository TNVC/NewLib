#include <stdio.h>
#include <assert.h>
#include "newstdio.h"
#include "newstring.h"

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

    for ( ; ch != '\n' && i < n - 1; ++i)
    {
        if((ch = getc(stream)) == EOF)
            return nullptr;

        str[i] = (char) ch;
    }

    str[i] = '\0';

    return str;
}

size_t newgetline(char **strPointer, size_t *n, FILE *stream)
{
    assert(strPointer != nullptr);
    assert(n          != nullptr);
    assert(stream     != nullptr);

    size_t size = 10;
    *strPointer = (char *) malloc(size);

    int ch = 0;

    for (*n = 0; ch != '\n'; ++(*n))
    {
        if (*n >= size)
        {
            size = size*2 + 1;

            *strPointer = (char *) realloc(*strPointer, size);
        }

        ch = getc(stream);

        if (ch == EOF)
        {
            (*strPointer)[(*n)++] = '\0';

            *strPointer = (char *) realloc(*strPointer, *n);

            return EOF;
        }

        (*strPointer)[*n] = (char) ch;
    }

    (*strPointer)[(*n)++] = '\0';

    *strPointer = (char *) realloc(*strPointer, *n);

    return *n;
}
