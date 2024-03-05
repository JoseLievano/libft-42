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

static int	is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static char *early_return(char const *s1, char const *set)
{
    if (!s1)
        return (NULL);
    if (!set){
        return (ft_strdup(s1));
    }
    return (NULL);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	char	*trimmed_str;

    if (!s1 || !set)
    {
        return (early_return(s1, set));
    }
	start = 0;
	end = ft_strlen(s1);
	while (s1[start] && is_in_set(s1[start], set))
		start++;
	while (end > start && is_in_set(s1[end - 1], set))
		end--;
	trimmed_str = (char *)malloc(sizeof(char) * (end - start + 1));
	if (!trimmed_str)
		return (NULL);
	if (start >= end)
		trimmed_str[0] = '\0';
	else
		ft_strlcpy(trimmed_str, s1 + start, end - start + 1);
	return (trimmed_str);
}
