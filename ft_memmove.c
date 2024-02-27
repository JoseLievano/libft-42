#include "libft.h"

void    *ft_memmove(void *dest, const void *src, size_t len)
{
    size_t  i;

    i = 0;
    if (!dest || !src)
        return (NULL);

    if (dest < src)
    {
        while (i < len)
        {
            ((unsigned char *)dest)[i] = ((unsigned char *)src)[i];
            i++;
        }
    }
    else
    {
        while (i < len)
        {
            ((unsigned char *)dest)[len - 1 - i] = ((unsigned char *)src)[len - 1 - i];
            i++;
        }
    }
    return (dest);

}