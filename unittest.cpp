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
static int testString(const char *real    ,
                       const char *expected, unsigned numTest);

/// Compare two integers
/// @param [in] real Real value of int
/// @param [in] expected Expected value of int
/// @param [in] numTest Number of test
/// @return expected == real
static int testInt(int real    ,
                    int expected, unsigned numTest);

/// Compare two pointers
/// @param [in] real Real value of pointer
/// @param [in] expected Expected value of pointer
/// @param [in] numTest Number of test
/// @return expected == real
static int testPointer(const void *real    ,
                        const void *expected, unsigned numTest);


/// Show test result
/// @param [in] succesful Count of succesful tests
/// @param [in] failed Count of failed tests
/// @param [in] funcName Name of testing function
static void showTestResult(unsigned succesful, unsigned failed, const char *funcName);

/// Set all chars in string to '\\0'
/// @param [out] str String for zeroing
/// @param [in] n Length of string
static void cleanString(char *str, int n);

/// If string equals "0", set all chars in string yo "\\0"
/// @param [out] str String for zeroing
/// @param [in] n Length of string
static void ifZeroStringCleanString(char *str, int n);


void test_newstrchr()
{
    FILE *fileptr = nullptr;

    fileptr = fopen ("test/strchr.txt", "r");

    if (fileptr == nullptr)
    {
        printf("Hasn`t test for %s()", __func__);

        return;
    }

    unsigned testCount = 0;

    unsigned succesful = 0,
             failed    = 0;

    char ch                    = '\0';
    char str[MAX_TEST_STR_LEN] =   "";

    int pos = 0;

    while (fscanf(fileptr, "%s %c %d", str, &ch, &pos) == 3)
    {
        ++testCount;

        if (testPointer(newstrchr(str, ch == '0' ? '\0' : ch), pos == -1 ? nullptr : str + pos, testCount))
            ++succesful;
        else
            ++failed;
    }

    showTestResult(succesful, failed, "newstrchr()");
}

void test_newstrlen()
{
    FILE *fileptr = nullptr;

    fileptr = fopen ("test/strlen.txt", "r");

    if (fileptr == nullptr)
    {
        printf("Hasn`t test for %s()", __func__);

        return;
    }

    unsigned testCount = 0;

    unsigned succesful = 0,
             failed    = 0;

    char str[MAX_TEST_STR_LEN] = "";

    int len = 0;

    while (fscanf(fileptr, "%s %d", str, &len) == 2)
    {
        ++testCount;

        if (testInt((int) newstrlen(str), len, testCount))
            ++succesful;
        else
            ++failed;
    }

    showTestResult(succesful, failed, "newstrlen()");
}

void test_newstrcpy()
{
    FILE *fileptr = nullptr;

    fileptr = fopen ("test/strcpy.txt", "r");

    if (fileptr == nullptr)
    {
        printf("Hasn`t test for %s()", __func__);

        return;
    }

    unsigned testCount = 0;

    unsigned succesful = 0,
             failed    = 0;

    char origin[MAX_TEST_STR_LEN] = "";
    char   copy[MAX_TEST_STR_LEN] = "";

    while (fscanf(fileptr, "%s %s", copy, origin) == 2)
    {
        ++testCount;

        ifZeroStringCleanString(origin, MAX_TEST_STR_LEN);

        ifZeroStringCleanString(copy  , MAX_TEST_STR_LEN);

        if (testString(newstrcpy(copy, origin), origin, testCount))
            ++succesful;
        else
            ++failed;
    }

    showTestResult(succesful, failed, "newstrcpy()");
}

void test_newstrncpy()
{
    FILE *fileptr = nullptr;

    fileptr = fopen ("test/strncpy.txt", "r");

    if (fileptr == nullptr)
    {
        printf("Hasn`t test for %s()", __func__);

        return;
    }

    unsigned testCount = 0;

    unsigned succesful = 0,
             failed    = 0;

    char origin[MAX_TEST_STR_LEN] = "";
    char   copy[MAX_TEST_STR_LEN] = "";
    char result[MAX_TEST_STR_LEN] = "";

    int len = 0;

    while (fscanf(fileptr, "%s %s %s %d", copy, origin, result, &len) == 4)
    {
        ++testCount;

        ifZeroStringCleanString(origin, MAX_TEST_STR_LEN);

        ifZeroStringCleanString(copy  , MAX_TEST_STR_LEN);

        ifZeroStringCleanString(result, MAX_TEST_STR_LEN);

        if (testString(newstrncpy(copy, origin, len), result, testCount))
            ++succesful;
        else
            ++failed;
    }

    showTestResult(succesful, failed, "newstrncpy()");
}

void test_newstrcat()
{
    FILE *fileptr = nullptr;

    fileptr = fopen ("test/strcat.txt", "r");

    if (fileptr == nullptr)
    {
        printf("Hasn`t test for %s()", __func__);

        return;
    }

    unsigned testCount = 0;

    unsigned succesful = 0,
             failed    = 0;

    char origin[MAX_TEST_STR_LEN] = "";
    char adding[MAX_TEST_STR_LEN] = "";
    char result[MAX_TEST_STR_LEN] = "";

    while (fscanf(fileptr, "%s %s %s", origin, adding, result) == 3)
    {
        ++testCount;

        ifZeroStringCleanString(origin, MAX_TEST_STR_LEN);

        ifZeroStringCleanString(adding, MAX_TEST_STR_LEN);

        ifZeroStringCleanString(result, MAX_TEST_STR_LEN);

        if (testString(newstrcat(origin, adding), result, testCount))
            ++succesful;
        else
            ++failed;
    }

    showTestResult(succesful, failed, "newstrcat()");
}

void test_newstrncat()
{
    FILE *fileptr = nullptr;

    fileptr = fopen ("test/strncat.txt", "r");

    if (fileptr == nullptr)
    {
        printf("Hasn`t test for %s()", __func__);

        return;
    }

    unsigned testCount = 0;

    unsigned succesful = 0,
             failed    = 0;

    char origin[MAX_TEST_STR_LEN] = "";
    char adding[MAX_TEST_STR_LEN] = "";
    char result[MAX_TEST_STR_LEN] = "";

    int len = 0;

    while (fscanf(fileptr, "%s %s %s %d", origin, adding, result, &len) == 4)
    {
        ++testCount;

        ifZeroStringCleanString(origin, MAX_TEST_STR_LEN);

        ifZeroStringCleanString(adding, MAX_TEST_STR_LEN);

        ifZeroStringCleanString(result, MAX_TEST_STR_LEN);

        if (testString(newstrncat(origin, adding, len), result, testCount))
            ++succesful;
        else
            ++failed;
    }

    showTestResult(succesful, failed, "newstrncat()");
}

void test_newstrdup()
{
    FILE *fileptr = nullptr;

    fileptr = fopen ("test/strdup.txt", "r");

    if (fileptr == nullptr)
    {
        printf("Hasn`t test for %s()", __func__);

        return;
    }

    unsigned testCount = 0;

    unsigned succesful = 0,
             failed    = 0;

    char str[MAX_TEST_STR_LEN] = "";

    while (fscanf(fileptr, "%s", str) == 1)
    {
        ++testCount;

        char *copy = strdup(str);

        if (testString(copy, str, testCount))
            ++succesful;
        else
            ++failed;

        free(copy);
    }

    showTestResult(succesful, failed, "newstrdup()");
}

void test_newputs()
{}

void test_newfgets()
{}

void test_newgetline()
{}

static int testPointer(const void *real, const void *expected, unsigned numTest)
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

static int testInt(int real, int expected, unsigned numTest)
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

static int testString(const char *real, const char *expected, unsigned numTest)
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

static void ifZeroStringCleanString(char *str, int n)
{
    if (strcmp(str, "0") == 0)
        cleanString(str, n);
}

static void cleanString(char *str, int n)
{
    for (int i = 0; i < n; ++i)
        str[i] = '\0';
}
