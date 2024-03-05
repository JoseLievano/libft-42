/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:56:51 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/04 00:58:48 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Check if a character 'c' is within the set 'set'.
static int is_in_set(char c, char const *set)
{
    while (*set)
    {
        if (c == *set)
            return (1);
        set++;
    }
    return (0);
}

// Handle special cases for NULL input and empty 'set'.
static char *early_return(char const *s1, char const *set)
{
    if (!s1)
        return (NULL);
    if (!set)
        return (ft_strdup(s1));
    return (NULL);
}

// Find the start index of the string after trimming characters in 'set'.
static size_t find_start(char const *s1, char const *set)
{
    size_t start = 0;
    while (s1[start] && is_in_set(s1[start], set))
        start++;
    return start;
}

// Find the end index of the string before trimming characters in 'set'.
static size_t find_end(char const *s1, char const *set, size_t start)
{
    size_t end = ft_strlen(s1);
    while (end > start && is_in_set(s1[end - 1], set))
        end--;
    return end;
}

// Allocate and create the trimmed string based on the start and end indices.
static char *create_trimmed_str(char const *s1, size_t start, size_t end)
{
    char *trimmed_str;

    trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!trimmed_str)
        return (NULL);
    if (start >= end)
        trimmed_str[0] = '\0';
    else
        ft_strlcpy(trimmed_str, s1 + start, end - start + 1);
    return trimmed_str;
}

// The main function that uses helper functions to trim the string.
char *ft_strtrim(char const *s1, char const *set)
{
    size_t start;
    size_t end;

    if (!s1 || !set)
    {
        return (early_return(s1, set));
    }
    start = find_start(s1, set);
    end = find_end(s1, set, start);
    return create_trimmed_str(s1, start, end);
}