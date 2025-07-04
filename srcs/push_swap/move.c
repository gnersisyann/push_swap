/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:58:58 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 17:59:22 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	move_from_to(t_push_swap *data, t_locations from, t_locations to)
{
	if (from == TOP_A)
		move_from_top_a(data, to);
	else if (from == TOP_B)
		move_from_top_b(data, to);
	else if (from == BOTTOM_A)
		move_from_bottom_a(data, to);
	else if (from == BOTTOM_B)
		move_from_bottom_b(data, to);
	return (1);
}

void	move_from_top_a(t_push_swap *data, t_locations to)
{
	if (to == TOP_B)
		push_b(data);
	else if (to == BOTTOM_A)
		rotate_a(data);
	else if (to == BOTTOM_B)
	{
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_top_b(t_push_swap *data, t_locations to)
{
	if (to == TOP_A)
		push_a(data);
	else if (to == BOTTOM_B)
		rotate_b(data);
	else if (to == BOTTOM_A)
	{
		push_a(data);
		rotate_a(data);
	}
}

void	move_from_bottom_a(t_push_swap *data, t_locations to)
{
	if (to == TOP_A)
		r_rotate_a(data);
	else if (to == TOP_B)
	{
		r_rotate_a(data);
		push_b(data);
	}
	else if (to == BOTTOM_B)
	{
		r_rotate_a(data);
		push_b(data);
		rotate_b(data);
	}
}

void	move_from_bottom_b(t_push_swap *data, t_locations to)
{
	if (to == TOP_B)
		r_rotate_b(data);
	else if (to == TOP_A)
	{
		r_rotate_b(data);
		push_a(data);
	}
	else if (to == BOTTOM_A)
	{
		r_rotate_b(data);
		push_a(data);
		rotate_a(data);
	}
}
