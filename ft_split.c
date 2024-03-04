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

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

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

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	**split;

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
					free(split[--k]);
				free(split);
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
