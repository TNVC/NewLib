#ifndef UNITTEST_H_
#define UNITTEST_H_

/// Max length of string in test files
static const int MAX_TEST_STR_LEN = 63;

/// Test function "newstrchr()"
void test_newstrchr();

/// Test function "newstrlen()"
void test_newstrlen();

/// Test function "newstrcpy()"
void test_newstrcpy();

/// Test function "newstrncpy()"
void test_newstrncpy();

/// Test function "newstrcat()"
void test_newstrcat();

/// Test function "newstrncat()"
void test_newstrncat();

/// Test function "newstrdup()"
void test_newstrdup();

/// Test function "newputs()"
/// @note There is no test
void test_newputs();

/// Test function "newfgets()"
void test_newfgets();

/// Test function "getline()"
void test_newgetline();

#endif
