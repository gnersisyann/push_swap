/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:08 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:48:08 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*offset;
	unsigned char	target;

	target = (unsigned char)c;
	offset = (char *)s;
	while (*offset)
	{
		if (*offset == target)
			return (offset);
		offset++;
	}
	if (target == '\0')
		return (offset);
	return (NULL);
}
