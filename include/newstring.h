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

/// Copy source string to target string
/// @details
///
/// @param [out] target New copy of source string
/// @param [in] source Origin string for copy
/// @param [in] n Count of max char to copy
/// @return Address of target string
char *newstrncpy(char *target, const char *source, int n);

/// Add source to end to target
/// @param [in/out] target First string in concatenation
/// @param [in] source Second string in concatenation
/// @return Address of target
char *newstrcat(char *target, const char *source);

/// Add source to end to target
/// @details
///
/// @param [in/out] target First string in concatenation
/// @param [in] source Second string in concatenation
/// @param [in] n Count of free space in target
/// @return Address of target
/// @note n don`t include '\\0'
char *newstrncat(char *target, const char *source, int n);

#endif
