/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:00:42 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 18:14:07 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/stack.h"

static void	r_rotate(t_stack *stk)
{
	if (is_full(stk))
	{
		stk->top = stk->bottom;
		stk->bottom = next_up(stk, stk->bottom);
	}
	else
	{
		stk->top = next_up(stk, stk->top);
		stk->data[stk->top] = stk->data[stk->bottom];
		stk->data[stk->bottom] = 0;
		stk->bottom = next_up(stk, stk->bottom);
	}
}

void	r_rotate_a(t_push_swap *data)
{
	t_operations	op;

	r_rotate(&data->a);
	op = rra;
	ft_lstadd_back(&data->op_list, ft_lstnew(&op));
}

void	r_rotate_b(t_push_swap *data)
{
	t_operations	op;

	r_rotate(&data->b);
	op = rrb;
	ft_lstadd_back(&data->op_list, ft_lstnew(&op));
}

void	r_rotate_ab(t_push_swap *data)
{
	t_operations	op;

	r_rotate(&data->a);
	r_rotate(&data->b);
	op = rrr;
	ft_lstadd_back(&data->op_list, ft_lstnew(&op));
}
