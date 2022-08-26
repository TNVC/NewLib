#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "newstdio.h"
#include "newstring.h"
#include "unittest.h"

int main()
{
    test_newstrchr();

    test_newstrlen();

    test_newstrcpy();

    test_newstrncpy();

    test_newstrcat();

    test_newstrncat();

    test_newstrdup();

    return 0;
}
