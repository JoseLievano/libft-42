/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 00:59:12 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/07 11:09:23 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	len_modifier(size_t *len, char const *str)
{
	if (*len > ft_strlen(str))
		*len = ft_strlen(str);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*substr;

	if (!str)
		return (NULL);
	if (start > ft_strlen(str))
		return ('\0');
	len_modifier(&len, str);
	i = 0;
	substr = (char *) malloc(sizeof(char) * (len + 1));
	if (!substr)
		return (NULL);
	while (i < len)
	{
		substr[i] = str[i + start];
		i++;
	}
	substr[i] = '\0';
	return (substr);
}
