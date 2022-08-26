#include <assert.h>
#include "newstring.h"

char *newstrchr(const char *str, char ch)
{
    assert(str != nullptr);

    const char *currentCh = str;

    for ( ; *currentCh; ++currentCh)
        if (*currentCh == ch)
            return (char *) currentCh;

    if (*currentCh == ch)
        return (char *) currentCh;

    return nullptr;
}

size_t newstrlen(const char *str)
{
    assert(str != nullptr);

    size_t size = 0;

    for (const char *ch = str; *ch; ++ch)
        ++size;

    return size;
}

char *newstrcpy(char *target, const char *source)
{
    assert(target != nullptr);
    assert(source != nullptr);

    int i = 0;

    for ( ; source[i]; ++i)
        target[i] = source[i];

    target[i] = source[i];

    return target;
}

char *newstrncpy(char *target, const char *source, int n)
{
    assert(target != nullptr);
    assert(source != nullptr);

    int i = 0;

    for ( ; source[i] && i < n - 1; ++i)
        target[i] = source[i];

    target[i]     = source[i];
    target[n - 1] = '\0';

    return target;
}

char *newstrcat(char *target, const char *source)
{
    assert(target != nullptr);
    assert(source != nullptr);

    int i = -1;
    while (target[++i])
        continue;

    int j = 0;
    for ( ; source[j]; ++j, ++i)
        target[i] = source[j];

    target[i] = source[j];

    return target;
}
