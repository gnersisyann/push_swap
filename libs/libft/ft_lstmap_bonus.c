/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:47:34 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:47:35 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result;
	t_list	*ptr;

	if (!lst)
		return (NULL);
	result = ft_lstnew(f(lst->content));
	if (!result)
		return (NULL);
	ptr = result;
	lst = lst->next;
	while (lst)
	{
		ptr->next = ft_lstnew(f(lst->content));
		if (!ptr->next)
		{
			ft_lstclear(&result, del);
			return (NULL);
		}
		ptr = ptr->next;
		lst = lst->next;
	}
	return (result);
}
