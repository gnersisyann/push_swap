/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:47:55 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:55 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dest, int c, size_t n)
{
	char	*offset;
	size_t	i;

	offset = (char *)dest;
	i = 0;
	while (i++ < n)
		*offset++ = (unsigned char)c;
	return (dest);
}
