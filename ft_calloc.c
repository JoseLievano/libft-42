#include "libft.h"

void *ft_calloc(size_t count, size_t size)
{
    size_t  space;
    void *arr;

    if (size != 0 && count > SIZE_MAX / size)
        return NULL;

    space = count * size;

    arr = malloc(space);
    if  (arr == NULL)
        return NULL;

    ft_bzero(arr, space);

    return arr;
}