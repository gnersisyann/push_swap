/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:48:26 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:48:26 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	char	*ptr;
	size_t	i;

	ptr = (char *)s;
	res = (char *)malloc(ft_strlen(s) + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (ptr[i])
	{
		res[i] = f(i, ptr[i]);
		i++;
	}
	res[i] = '\0';
	return (res);
}
