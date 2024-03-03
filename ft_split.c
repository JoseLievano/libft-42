#include "libft.h"

static size_t count_words(char const *s, char c)
{
    size_t i;
    size_t count;

    if (!s)
        return (0);
    i = 0;
    count = 0;

    while (s[i])
    {
        if (s[i] != c)
        {
            while (s[i] != c && s[i])
                i++;
            count++;
        }
        else
            i++;
    }
    return (count);
}

char **ft_split(char const *s, char c)
{
    size_t i;
    size_t j;
    size_t k;
    char **split;

    if (!s || !(split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1))))
        return (NULL);
    i = 0;
    k = 0;
    while (s[i])
    {
        if (s[i] != c)
        {
            j = i;
            while (s[i] != c && s[i])
                i++;
            if (!(split[k] = (char *)malloc(sizeof(char) * (i - j + 1))))
            {
                while (k > 0)
                    free(split[--k]); // Free previously allocated strings
                free(split); // Free the array of strings
                return (NULL);
            }
            ft_strlcpy(split[k++], s + j, i - j + 1);
        }
        else
            i++;
    }
    split[k] = NULL;
    return (split);
}