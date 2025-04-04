/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:30 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:48:31 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	s2_len;

	if (!*s2)
		return ((char *)(s1));
	s2_len = ft_strlen(s2);
	i = 0;
	while (s1[i] && i + s2_len <= len)
	{
		if (!ft_strncmp(&s1[i], s2, s2_len))
			return ((char *)(&s1[i]));
		i++;
	}
	return (NULL);
}
