#include "libft.h"

void    *ft_memset(void *str, int c, size_t len)
{
    size_t  i;

    if (str == NULL)
        return (NULL);
    i = 0;
    while (i < len)
    {
        ((unsigned char *)str)[i] = (unsigned char)c;
        i++;
    }
    return (str);
}