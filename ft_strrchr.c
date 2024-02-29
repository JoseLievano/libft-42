#include "libft.h"

char *ft_strrchr(const char *str, int c)
{
    size_t i;

    // Start one position past the end of the string to include the null terminator
    i = ft_strlen(str);

    // Check the null terminator if c is '\0'
    if (c == '\0')
        return (char *)(str + i);

    // Loop from the end of the string to the beginning
    while (i > 0)
    {
        i--; // Decrement first to avoid accessing out of bounds
        if (str[i] == (char)c)
            return (char *)&str[i]; // Cast to char* since str is const char*
    }

    // If c was not found, return NULL
    return NULL;
}