/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:10 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:48:11 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*copy;
	size_t	size;

	size = ft_strlen(s);
	copy = (char *)malloc(size + 1);
	if (!copy)
		return (0);
	size = 0;
	while (s[size])
	{
		copy[size] = s[size];
		size++;
	}
	copy[size] = '\0';
	return (copy);
}
