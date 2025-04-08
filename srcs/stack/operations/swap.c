/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:47 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/08 12:53:37 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/stack.h"

static void	swap(t_stack *stk)
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
	swap(&data->a);
	if (!data->checker_mode)
		save_op(data, sa);
}

void	swap_b(t_push_swap *data)
{
	swap(&data->b);
	if (!data->checker_mode)
		save_op(data, sb);
}

void	swap_ab(t_push_swap *data)
{
	swap(&data->a);
	swap(&data->b);
	if (!data->checker_mode)
		save_op(data, ss);
}
