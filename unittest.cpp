#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "newstring.h"
#include "unittest.h"

/// Compare two strings
/// @param [in] real Real value of string
/// @param [in] expected Expected value of string
/// @param [in] numTest Number of test
/// @return expected == real
static int testStrings(const char *real    ,
                       const char *expected, unsigned numTest);

/// Compare two integers
/// @param [in] real Real value of int
/// @param [in] expected Expected value of int
/// @param [in] numTest Number of test
/// @return expected == real
static int testInts(int real    ,
                    int expected, unsigned numTest);

/// Compare two pointers
/// @param [in] real Real value of pointer
/// @param [in] expected Expected value of pointer
/// @param [in] numTest Number of test
/// @return expected == real
static int testPointers(const void *real    ,
                        const void *expected, unsigned numTest);


/// Show test result
/// @param [in] succesful Count of succesful tests
/// @param [in] failed Count of failed tests
/// @param [in] funcName Name of testing function
static void showTestResult(unsigned succesful, unsigned failed, const char *funcName);

void test_newstrchr()
{
    unsigned numTest = 1;

    unsigned succesful = 0,
             failed    = 0;

    char str[7] = "abcdef";

    size_t i = 0;

    for ( ; i < strlen(str); ++i, ++numTest)
        if (testPointers(newstrchr(str, (char) ('a' + i)), str + i, numTest))
            ++succesful;
        else
            ++failed;

    for ( ; i < strlen(str) + 3; ++i, ++numTest)
        if (testPointers(newstrchr(str, (char) ('a' + i)), nullptr, numTest))
            ++succesful;
        else
            ++failed;

    if (testPointers(newstrchr(str, '\0'), str + strlen(str), numTest))
        ++succesful;
    else
        ++failed;

    showTestResult(succesful, failed, "newstrchr()");
}

void test_newstrlen()
{
    unsigned numTest = 1;

    unsigned succesful = 0,
             failed    = 0;

    const int len = 10;
    char str[len + 1] = "a";

    for (int i = 0; i < len; ++i, ++numTest)
    {
        if (testInts((int) newstrlen(str), i + 1, numTest))
            ++succesful;
        else
            ++failed;

        str[i + 1] = 'a';
    }

    showTestResult(succesful, failed, "newstrlen()");
}

void test_newstrcpy()
{
    unsigned numTest = 1;

    unsigned succesful = 0,
             failed    = 0;

    const int len = 10;
    char origin[len + 1] = "a";
    char copy[len + 1] = "";

    for (int i = 0; i < len; ++i, ++numTest)
    {
        if (testStrings(newstrcpy(copy, origin), origin, numTest))
            ++succesful;
        else
            ++failed;

        origin[i + 1] = (char) ('a' + i);
    }

    showTestResult(succesful, failed, "newstrcpy()");
}

void test_newstrncpy()
{
    unsigned numTest = 1;

    unsigned succesful = 0,
             failed    = 0;

    const int len = 5;
    char origin[len + 1] = "a";
    char copy[len + 1] = "";

    for (int i = 0; i < len; ++i, ++numTest)
    {
        if (testStrings(newstrncpy(copy, origin, i + 2), origin, numTest))
            ++succesful;
        else
            ++failed;

        origin[i + 1] = (char) ('a' + i);
    }

    if (testStrings(newstrncpy(copy, "1234567890", len + 1), "12345", numTest++))
            ++succesful;
        else
            ++failed;

    showTestResult(succesful, failed, "newstrncpy()");
}

void test_newstrcat()
{
    unsigned numTest = 1;

    unsigned succesful = 0,
             failed    = 0;

    char source[10] = "qwerty";
    char target[10] = "str";



    showTestResult(succesful, failed, "newstrcat()");
}

void test_newstrncat()
{}

void test_newstrdup()
{}

static int testPointers(const void *real, const void *expected, unsigned numTest)
{
    if (!(expected == real))
    {
        printf("-----------------------\n");
        printf("# Test %u failed:\n# Expected pointer: %p\n# Real     pointer: %p\n", numTest, expected, real);
        printf("-----------------------\n");

        return 0;
    }

    return 1;
}

static int testInts(int real, int expected, unsigned numTest)
{
    if (!(expected == real))
    {
        printf("-----------------------\n");
        printf("# Test %u failed:\n# Expected integer: %d\n# Real     integer: %d\n", numTest, expected, real);
        printf("-----------------------\n");

        return 0;
    }

    return 1;
}

static int testStrings(const char *real, const char *expected, unsigned numTest)
{
    if (!(strcmp(expected, real) == 0))
    {
        printf("-----------------------\n");
        printf("# Test %u failed:\n# Expected string: %s\n# Real     string: %s\n", numTest, expected, real);
        printf("-----------------------\n");

        return 0;
    }

    return 1;
}

static void showTestResult(unsigned succesful, unsigned failed, const char *funcName)
{
    printf("-----------------------\n");
    printf("# %s:\n# Total succesful: %4d\n# Total failed   : %4d\n",funcName, succesful, failed);
    printf("-----------------------\n");
}
