/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_operations.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:12 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 17:59:29 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	chunk_value(t_push_swap *data, t_chunk *chunk, int n)
{
	t_locations	loc;
	t_stack		*stk;
	int			i;

	loc = chunk->loc;
	stk = loc_to_stack(data, loc);
	if (loc == TOP_A || loc == TOP_B)
		i = stk->top;
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		i = stk->bottom;
	if (loc == TOP_A || loc == TOP_B)
		while (--n > 0)
			i = next_down(stk, i);
	else if (loc == BOTTOM_A || loc == BOTTOM_B)
		while (--n > 0)
			i = next_up(stk, i);
	return (stk->data[i]);
}

int	chunk_max_value(t_push_swap *data, t_chunk *chunk)
{
	t_stack	*stk;
	int		size;
	int		max_value;
	int		i;

	stk = loc_to_stack(data, chunk->loc);
	size = chunk->size;
	max_value = 0;
	if (chunk->loc == TOP_A || chunk->loc == TOP_B)
		i = stk->top;
	else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
		i = stk->bottom;
	while (size--)
	{
		if (stk->data[i] > max_value)
			max_value = stk->data[i];
		if (chunk->loc == TOP_A || chunk->loc == TOP_B)
			i = next_down(stk, i);
		else if (chunk->loc == BOTTOM_A || chunk->loc == BOTTOM_B)
			i = next_up(stk, i);
	}
	return (max_value);
}

t_stack	*loc_to_stack(t_push_swap *data, t_locations loc)
{
	if (loc == TOP_A || loc == BOTTOM_A)
		return (&data->a);
	else
		return (&data->b);
}
