/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 18:01:08 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 18:01:16 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/stack.h"

int	current_size(t_stack *stk)
{
	if (!stk || !stk->data)
		return (0);
	if (stk->top == stk->bottom)
	{
		if (stk->data[stk->top] == 0)
			return (0);
		return (1);
	}
	if (stk->top > stk->bottom)
		return ((stk->size - stk->top) + stk->bottom + 1);
	else
		return (stk->bottom - stk->top + 1);
}

int	next_up(t_stack *stk, int index)
{
	if (current_size(stk) == 0)
		return (index);
	if (index == 0)
		return (stk->size - 1);
	else
		return (index - 1);
}

int	next_down(t_stack *stk, int index)
{
	if (current_size(stk) == 0)
		return (index);
	if (index == stk->size - 1)
		return (0);
	else
		return (index + 1);
}

int	is_full(t_stack *stk)
{
	return (stk->size == current_size(stk));
}

int	value(t_stack *stk, int n)
{
	int	i;

	i = stk->top;
	while (--n > 0)
		i = next_down(stk, i);
	return (stk->data[i]);
}
