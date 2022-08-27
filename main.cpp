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

    char *str = nullptr;

    size_t size = 0;

    puts("Input a string:");

    if (newgetline(&str, &size, stdin) == 0)
        return 0;

    printf("%s", str);

    free(str);

    puts("Goodbye");

    #endif

    return 0;
}
