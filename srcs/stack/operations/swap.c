/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:47 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 18:12:55 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/stack.h"

void	swap(t_stack *stk)
{
	int	tmp;

	if (stk->data[next_down(stk, stk->top)] == 0)
		return ;
	tmp = stk->data[next_down(stk, stk->top)];
	stk->data[next_down(stk, stk->top)] = stk->data[stk->top];
	stk->data[stk->top] = tmp;
}

void	swap_a(t_push_swap *data)
{
	t_operations	op;

	swap(&data->a);
	op = sa;
	ft_lstadd_back(&data->op_list, ft_lstnew(&op));
}

void	swap_b(t_push_swap *data)
{
	t_operations	op;

	swap(&data->b);
	op = sb;
	ft_lstadd_back(&data->op_list, ft_lstnew(&op));
}

void	swap_ab(t_push_swap *data)
{
	t_operations	op;

	swap(&data->a);
	swap(&data->b);
	op = ss;
	ft_lstadd_back(&data->op_list, ft_lstnew(&op));
}
