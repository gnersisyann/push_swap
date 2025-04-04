/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:28 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:48:29 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_offset;
	unsigned char	*s2_offset;

	s1_offset = (unsigned char *)s1;
	s2_offset = (unsigned char *)s2;
	while (n-- > 0)
	{
		if (*s1_offset - *s2_offset != 0)
			return (*s1_offset - *s2_offset);
		else if (*s1_offset == '\0' && *s2_offset == '\0')
			return (0);
		s1_offset++;
		s2_offset++;
	}
	return (0);
}
