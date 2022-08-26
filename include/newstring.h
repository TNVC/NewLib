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

/// Copy source string to target string
/// @param [out] target New copy of source string
/// @param [in] source Origin string for copy
/// @return Address of target string
char *newstrcpy(char *target, const char *source);

#endif
