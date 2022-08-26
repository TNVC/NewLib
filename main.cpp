#include <stdio.h>
#include "newstdio.h"
#include "newstring.h"

int main()
{
    newputs("First line\nSecond line");
    newputs("Third line");

    const char *str = "Qwerty";
    printf("\"Qwerty\" has \'e\' in %lld index\n",  newstrchr(str, 'e') - str);
    printf("\"Qwerty\" has \'\\0\' in %lld index\n",  newstrchr(str, '\0') - str);
    printf("\"Qwerty\" hasn`t \'a\'. Pointer is %p\n",  newstrchr(str, 'a'));

    return 0;
}
