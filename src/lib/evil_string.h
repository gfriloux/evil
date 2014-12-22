#ifndef __EVIL_STRING_H__
#define __EVIL_STRING_H__


/**
 * @file evil_string.h
 * @brief The file that provides functions ported from Unix in string.h.
 * @defgroup Evil_String_Group String.h functions.
 *
 * This header provides functions ported from Unix in string.h.
 *
 * @{
 */


#ifdef _WIN32_WCE

/*
 * Environment variable related functions
 *
 */

/**
 * @brief Return the static string "[Windows CE] error\n".
 *
 * @param errnum Unused parameter.
 * @return The static string "[Windows CE] error\n".
 *
 * This function just returns the static string "[Windows CE]
 * error\n".
 *
 * Conformity: Non applicable.
 *
 * Supported OS: Windows CE (not cegcc).
 */
EAPI char *strerror (int errnum);

#endif /* _WIN32_WCE */

/*
 * bit related functions
 *
 */

/**
 * @brief Return the position of the first (least significant) bit set in a word
 *
 * @param i Word to take the first bit.
 * @return The position of the first bit set, or 0 if no bits are set.
 *
 * This function returns the position of the first (least significant)
 * bit set in @p i. The least significant bit is position 1 and the
 * most significant position e.g. 32 or 64. The function returns 0 if
 * no bits are set in @p i, or the position of the first bit set
 * otherwise.
 *
 * Conformity: BSD
 *
 * Supported OS: Windows XP, Windows CE (not cegcc).
 */
EAPI int ffs(int i);


#ifdef _WIN32_WCE

/*
 * String manipulation related functions
 *
 */

/**
 * @brief Compare two strings.
 *
 * @param s1 The first string to compare.
 * @param s2 The second string to compare.
 * @return < 0 if s1 < s2, >0 if s1 > s2, 0 otherwise.
 *
 * This function is exactly the same as strcmp(). No possible way to
 * achieve the behavior of strcoll() on Windows CE.
 *
 * Conformity: Non applicable.
 *
 * Supported OS: Windows CE.
 */
EAPI int strcoll (const char *s1, const char *s2);

#endif /* _WIN32_WCE */

/**
 * @brief Get the last substring occurence.
 *
 * @param str The string to search from.
 * @param substr The substring to search.
 * @return The last occurrence of the substring if found, @c NULL otherwise.
 *
 * This function retrieves the last occurrence of @p substring in the
 * string @p str. If @p str or @p substr are @c NULL, of if @p substr
 * is not found in @p str, @c NULL is returned.
 *
 * Conformity: Non applicable.
 *
 * Supported OS: Windows XP, Windows CE.
 */
EAPI char *strrstr (const char *str, const char *substr);

#ifdef _MSC_VER

/**
 * @brief Compare two string, ignoring case.
 *
 * @param s1 The first string to compare.
 * @param s2 The first string to compare.
 * @return
 *
 * This function compares the two strings @p s1 and @p s2, ignoring
 * the case of the characters. It returns an integer less than, equal
 * to, or greater than zero if s1 is found, respectively, to be less
 * than, to match, or be greater than s2.
 *
 * Conformity: Non applicable.
 *
 * Supported OS: Windows XP (vc++ only)
 */
EAPI int strcasecmp(const char *s1, const char *s2);

#endif /* _MSC_VER */

/**
 * @brief Locatea substring into a string, ignoring case.
 *
 * @param haystack The string to search in.
 * @param needle The substring to find.
 * @return
 *
 * This function locates the string @p needle into the string @p haystack,
 * ignoring the case of the characters. It returns apointer to the
 * beginning of the substring, or NULL if the substring is not found.
 * If @p haystack or @p needle are @c NULL, this function returns @c NULL.
 *
 * Conformity: Non applicable.
 *
 * Supported OS: Windows XP, Windows CE
 */
EAPI char *strcasestr(const char *haystack, const char *needle);

/**
 * @brief Returns a pointer to a cupy of @b s.
 *
 * @param s The string to duplicate.
 * @param n The number of chars to duplicate.
 * @return
 *
 * Returns a pointer to a copy of @var{s} with at most @var{n} characters
 * in memory obtained from @code{malloc}, or @code{NULL} if insufficient
 * memory was available.  The result is always NUL terminated.
 *
 * Conformity: POSIX.1-2008
 *
 * Supported OS : Windows XP, Windows CE
 */
EAPI char *strndup(const char *s, size_t n);

/**
 * @brief Find the last occurrence of 'c' in the buffer 's' of size 'n'.
 *
 * @param s The memory area to search.
 * @param c The char to find.
 * @param n The size of the memory area.
 *
 * Conformity: Non applicable.
 *
 * Supported OS: Windows XP
 */
EAPI void *memrchr(const void *s, int c, size_t n);

/**
 * @}
 */


#endif /* __EVIL_STRING_H__ */
