#include "libft.h"

size_t ft_strlcpy(char *dest, const char *src, size_t size)
{
    size_t i = 0;
    size_t src_length;

    if (!src)
        return (0);

    src_length = ft_strlen(src);

    if (size > 0)
    {
        while (src[i] && i < (size - 1))
        {
            dest[i] = src[i];
            i++;
        }
        dest[i] = '\0';
    }

    return src_length;
}