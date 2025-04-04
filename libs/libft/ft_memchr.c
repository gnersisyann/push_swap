/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:47:45 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:45 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*ptr;
	unsigned char	target;

	target = (unsigned char)c;
	ptr = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*ptr == target)
			return ((void *)(ptr));
		ptr++;
	}
	return (NULL);
}
