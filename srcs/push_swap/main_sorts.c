/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 17:59:01 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 17:59:54 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

int	is_sorted(t_push_swap *data)
{
	int	i;
	int	rank;

	i = data->a.top;
	rank = 1;
	while (rank <= data->a.size)
	{
		if (data->a.data[i] != rank)
			return (0);
		rank++;
		i = next_down(&data->a, i);
	}
	return (1);
}

void	sort(t_push_swap *data)
{
	if (data->a.size <= 1 || is_sorted(data))
		return ;
	else if (data->a.size == 3)
		sort_3(data);
	else if (data->a.size == 5)
		sort_5(data);
	else
		chunk_sort(data);
	// post_sort_optimization(data);
}
