/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:47:48 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:48 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*s1_offset;
	unsigned char	*s2_offset;

	s1_offset = (unsigned char *)s1;
	s2_offset = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*s1_offset - *s2_offset != 0)
			return (*s1_offset - *s2_offset);
		s1_offset++;
		s2_offset++;
	}
	return (0);
}
