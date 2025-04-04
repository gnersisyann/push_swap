/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:47:50 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:50 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char		*dest_offset;
	const char	*src_offset;
	size_t		i;

	if (!dest && !src)
		return (dest);
	dest_offset = (char *)dest;
	src_offset = (const char *)src;
	i = 0;
	while (i < n)
	{
		dest_offset[i] = src_offset[i];
		i++;
	}
	return (dest);
}
