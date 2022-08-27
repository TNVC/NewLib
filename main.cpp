#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "newstdio.h"
#include "newstring.h"
#include "unittest.h"

int main()
{
    #ifdef DEBUG_MODE_

    test_newstrchr();

    test_newstrlen();

    test_newstrcpy();

    test_newstrncpy();

    test_newstrcat();

    test_newstrncat();

    test_newstrdup();

    test_newputs();

    test_newfgets();

    test_newgetline();

    #else

    for (int i = 0; i < 1; ++i)
        putc('\0', fp);

    return 0;

    char *str = nullptr;

    size_t size = 0;

    if (getline(&str, &size, stdin) == (size_t) EOF)
        return -1;

    printf("%s", str);

    free(str);

    #endif

    return 0;
}
