/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:46 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/08 12:53:27 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/stack.h"

static void	rotate(t_stack *stk)
{
	if (is_full(stk))
	{
		stk->bottom = stk->top;
		stk->top = next_down(stk, stk->top);
	}
	else
	{
		stk->bottom = next_down(stk, stk->bottom);
		stk->data[stk->bottom] = stk->data[stk->top];
		stk->data[stk->top] = 0;
		stk->top = next_down(stk, stk->top);
	}
}

void	rotate_a(t_push_swap *data)
{
	rotate(&data->a);
	if (!data->checker_mode)
		save_op(data, ra);
}

void	rotate_b(t_push_swap *data)
{
	rotate(&data->b);
	if (!data->checker_mode)
		save_op(data, rb);
}

void	rotate_ab(t_push_swap *data)
{
	rotate(&data->a);
	rotate(&data->b);
	if (!data->checker_mode)
		save_op(data, rr);
}
