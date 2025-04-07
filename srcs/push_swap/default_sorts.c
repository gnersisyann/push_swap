/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   default_sorts.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:03 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 17:59:03 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_3(t_push_swap *ps)
{
	int	top_idx;
	int	mid_idx;
	int	bot_idx;

	top_idx = ps->a.top;
	mid_idx = next_down(&ps->a, top_idx);
	bot_idx = next_down(&ps->a, mid_idx);
	if (ps->a.data[top_idx] > ps->a.data[mid_idx]
		&& ps->a.data[mid_idx] > ps->a.data[bot_idx])
		return (swap_a(ps), r_rotate_a(ps));
	if (ps->a.data[top_idx] > ps->a.data[bot_idx]
		&& ps->a.data[bot_idx] > ps->a.data[mid_idx])
		return (rotate_a(ps));
	if (ps->a.data[mid_idx] > ps->a.data[top_idx]
		&& ps->a.data[top_idx] > ps->a.data[bot_idx])
		return (r_rotate_a(ps));
	if (ps->a.data[bot_idx] > ps->a.data[top_idx]
		&& ps->a.data[top_idx] > ps->a.data[mid_idx])
		return (swap_a(ps));
	if (ps->a.data[mid_idx] > ps->a.data[bot_idx]
		&& ps->a.data[bot_idx] > ps->a.data[top_idx])
		return (swap_a(ps), rotate_a(ps));
}

void	sort_5(t_push_swap *ps)
{
	while (current_size(&ps->a) > 3)
	{
		if (value(&ps->a, 1) == 1 || value(&ps->a, 1) == 2)
			push_b(ps);
		else
			rotate_a(ps);
	}
	if (value(&ps->b, 1) < value(&ps->b, 2))
		swap_b(ps);
	sort_3(ps);
	push_a(ps);
	push_a(ps);
}
