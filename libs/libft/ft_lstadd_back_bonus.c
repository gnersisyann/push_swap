/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:47:04 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:04 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *added)
{
	t_list	*last;

	if (!lst || !added)
		return ;
	if (!*lst)
	{
		*lst = added;
		return ;
	}
	last = ft_lstlast(*lst);
	last->next = added;
}
