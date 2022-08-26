#ifndef NEWSTDIO_H_
#define NEWSTDIO_H_

/// Print string and put '\\n' to end
/// @param [in] str String for output
/// @return Not negative number if all is OK and EOF if was error in write
int newputs(const char *str);

/// Read chars from stream
/// @details Read n - 1 or while don`t meet '\\n'\n
///          Always add '\\0' to end
///
/// @param [out] str Char array for write
/// @param [in] Count of cells for write chars (Size of array - 1)
/// @param [in] stream Chars input stream
/// @return Address of str or NULL if was read`s error
char *newfgets(char *str, int n, FILE *stream);

#endif
