#ifndef NEWSTRING_H_
#define NEWSTRING_H_

/// Find char in string
/// @param [in] str Source string
/// @param [in] ch Char which want to find
/// @return Pointer to first ch in str or NULL if str hasn`t ch
char *newstrchr(const char *str, char ch);

/// Count string length
/// @param [in] str Source string
/// @return Length of string ('\\0' don`t count)
size_t newstrlen(const char *str);

#endif
