/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:05 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 17:59:47 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	chunk_sort(t_push_swap *data)
{
	t_chunk	full_chunk;

	full_chunk.loc = TOP_A;
	full_chunk.size = data->a.size;
	recursive_chunk_sort(data, &full_chunk);
}

void	recursive_chunk_sort(t_push_swap *data, t_chunk *to_sort)
{
	t_split	dest;

	chunk_to_the_top(data, to_sort);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			sort_three(data, to_sort);
		else if (to_sort->size == 2)
			sort_two(data, to_sort);
		else if (to_sort->size == 1)
			sort_one(data, to_sort);
		return ;
	}
	chunk_split(data, to_sort, &dest);
	recursive_chunk_sort(data, &dest.max);
	recursive_chunk_sort(data, &dest.mid);
	recursive_chunk_sort(data, &dest.min);
}

void	chunk_split(t_push_swap *data, t_chunk *to_split, t_split *dest)
{
	int	pivot_1;
	int	pivot_2;
	int	max_value;
	int	next_value;

	innit_size(&dest->min, &dest->mid, &dest->max);
	set_split_loc(to_split->loc, &dest->min, &dest->mid, &dest->max);
	set_third_pivots(to_split->loc, to_split->size, &pivot_1, &pivot_2);
	max_value = chunk_max_value(data, to_split);
	while (to_split->size--)
	{
		next_value = chunk_value(data, to_split, 1);
		if (next_value > max_value - pivot_2)
			dest->max.size += move_from_to(data, to_split->loc, dest->max.loc);
		else if (next_value > max_value - pivot_1)
			dest->mid.size += move_from_to(data, to_split->loc, dest->mid.loc);
		else
			dest->min.size += move_from_to(data, to_split->loc, dest->min.loc);
	}
}
