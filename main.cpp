#include <stdio.h>
#include "newstdio.h"
#include "newstring.h"

static void showArray(const char *array, int n);

int main()
{
    newputs("First line\nSecond line");
    newputs("Third line");

    const char *str = "Qwerty";
    printf("\"Qwerty\" has \'e\' in %lld index\n",      newstrchr(str, 'e')  - str);
    printf("\"Qwerty\" has \'\\0\' in %lld index\n",    newstrchr(str, '\0') - str);
    printf("\"Qwerty\" hasn`t \'a\'. Pointer is %p\n",  newstrchr(str, 'a'));

    printf("Length of \"q\" is %zd\n",     newstrlen("q"));
    printf("Length of \"qw\" is %zd\n",    newstrlen("qw"));
    printf("Length of \"qwe\" is %zd\n",   newstrlen("qwe"));
    printf("Length of \"qwer\" is %zd\n",  newstrlen("qwer"));
    printf("Length of \"qwert\" is %zd\n", newstrlen("qwert"));

    char first [10] = "First";
    char second[10] = "Second";
    printf("first = %s, second = %s\n", first, second);
    printf("first = %s, second = %s\n", first, newstrcpy(second, first));

    char third [10] = "Third";
    char fourth[10] = "Fourth";
    printf("third = %s, fourth = %s\n", third, fourth);
    printf("third = %s, fourth = %s\n", newstrncpy(third, fourth, 10), fourth);

    char str0[4] = "Str";
    char str1[9] = "Qw";
    //printf("str0 = %s, str1 = %s, fourth = %s\n", newstrncpy(str0, str1, 4), str1, fourth);

    printf("str0 = %s, str1 = %s\n", str0, str1);

    showArray(str1, 9);
    newstrncat(str1, str0, 6);
    showArray(str1, 9);

    printf("str0 = %s, str1 = %s\n", str0, str1);

    return 0;
}

static void showArray(const char *array, int n)
{
    printf("%p: ", array);
    for (int i = 0; i < n; ++i)
        if (array[i] == '\0')
            printf("%d:\\0 ", i);
        else
            printf("%d:%c ", i, array[i]);
    putchar('\n');
}
