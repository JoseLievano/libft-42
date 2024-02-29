#include "libft.h"

int ft_strncmp(const char *str1, const char *str2, size_t len)
{
    size_t  i;

    i = 0;
    while (i < len && str1[i] && str2[i])
    {
        if((unsigned char)str1[i] != (unsigned char)str2[i])
            return (unsigned char) str1[i] - (unsigned char) str2[i];
        i++;
    }
    if (i < len)
    {
        return ((unsigned char) str1[i] - (unsigned char) str2[i]);
    }

    return (0);

}