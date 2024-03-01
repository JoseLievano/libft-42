#include "libft.h"

char    *ft_strjoin(char const *s1, char const *s2)
{
    char	*new_str;
    size_t	i;
    size_t	j;
    unsigned int mem_space;

    mem_space = sizeof (*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1);

    new_str = (char*)malloc(mem_space);
    if (!new_str)
        return (NULL);

    i = 0;
    j = 0;
    while (s1[i])
    {
        new_str[j++] = s1[i];
        i++;
    }
    i = 0;
    while (s2[i])
    {
        new_str[j++] = s2[i];
        i++;
    }
    new_str[j] = '\0';
    return (new_str);
}

