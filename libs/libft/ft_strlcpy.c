/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:20 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:48:20 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char	*dest_offset;
	char	*src_offset;
	size_t	result;

	dest_offset = dest;
	src_offset = (char *)src;
	result = ft_strlen(src);
	if (!size || dest == src)
		return (result);
	while (*src_offset && size-- - 1)
		*(dest_offset++) = *(src_offset++);
	*dest_offset = '\0';
	return (result);
}
