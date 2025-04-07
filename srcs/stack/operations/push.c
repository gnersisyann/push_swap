/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:44 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 18:14:25 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/stack.h"

void	push(t_stack *src, t_stack *dest)
{
	int	dest_i;

	if (is_full(dest))
		return ;
	dest_i = next_up(dest, dest->top);
	dest->data[dest_i] = src->data[src->top];
	dest->top = dest_i;
	src->data[src->top] = 0;
	src->top = next_down(src, src->top);
}

void	push_a(t_push_swap *data)
{
	t_operations	op;

	push(&data->b, &data->a);
	op = pa;
	ft_lstadd_back(&data->op_list, ft_lstnew(&op));
}

void	push_b(t_push_swap *data)
{
	t_operations	op;

	push(&data->a, &data->b);
	op = pb;
	ft_lstadd_back(&data->op_list, ft_lstnew(&op));
}
