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

    printf("Length of \"q\" is %zd\n", newstrlen("q"));
    printf("Length of \"qw\" is %zd\n", newstrlen("qw"));
    printf("Length of \"qwe\" is %zd\n", newstrlen("qwe"));
    printf("Length of \"qwer\" is %zd\n", newstrlen("qwer"));
    printf("Length of \"qwert\" is %zd\n", newstrlen("qwert"));

    return 0;
}
