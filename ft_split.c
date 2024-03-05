/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 23:37:50 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/03 23:44:46 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Counts the number of words separated by the delimiter 'c'
static size_t count_words(char const *s, char c)
{
    size_t i;
    size_t count;

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

// Allocates memory for the split array
static char **malloc_split(char const *s, char c)
{
    char **split;

    split = (char **)malloc(sizeof(char *) * (count_words(s, c) + 1));
    return (split);
}

// Frees the allocated memory for the split array in case of an error
static void free_split(char **split, size_t k)
{
    while (k > 0)
        free(split[--k]);
    free(split);
}

// Allocates memory for a word and copies the word into it
static char *malloc_word(char const *s, size_t start, size_t end)
{
    char *word;

    word = (char *)malloc(sizeof(char) * (end - start + 1));
    if (!word)
        return (NULL);
    ft_strlcpy(word, s + start, end - start + 1);
    return (word);
}

// Main function that splits the string into words
char **ft_split(char const *s, char c)
{
    size_t i;
    size_t j;
    size_t k;
    char **split;

    if (!s)
        return (NULL);
    split = malloc_split(s, c);
    if (!split)
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
            split[k] = malloc_word(s, j, i);
            if (!split[k])
            {
                free_split(split, k);
                return (NULL);
            }
            k++;
        }
        else
            i++;
    }
    split[k] = NULL;
    return (split);
}