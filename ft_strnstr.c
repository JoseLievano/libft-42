#include "libft.h"

#include <stdio.h>
char    *ft_strnstr(const char *haystack, const char *needle, size_t len)
{
    size_t	i;
    size_t  j;

    j = 0;
    i = 0;
    if (!*needle)
        return ((char *)haystack);
    while (haystack[i] && i < len)
    {
        j = 0;
        if (haystack[i] == needle[j])
        {
            while (needle[j] && haystack[i + j] == needle[j] && i + j < len)
            {
                j++;
            }
            if (!needle[j])
                return ((char *)&haystack[i]);
        }
        i++;
    }
    return (NULL);
}