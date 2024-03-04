/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jlievano <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 20:52:40 by jlievano          #+#    #+#             */
/*   Updated: 2024/03/03 20:55:51 by jlievano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	space;
	void	*arr;

	if (size != 0 && count > (UINT_MAX / size))
		return (NULL);
	space = count * size;
	arr = malloc(space);
	if (arr == NULL)
		return (NULL);
	ft_bzero(arr, space);
	return (arr);
}
