/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:05 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 16:02:34 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/stack.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_stack	st;

	if (argc < 2)
		return (0);
	validate_input(argc, argv);
	init_stack(&st, argc, argv);
	for (int i = 0; i < st.size; ++i)
	{
		printf("%d ", st.data[i]);
	}
	printf("\nSIZE->%d", st.size);
	printf("\nTOP->%d", st.top);
	printf("\nBOTTOM->%d\n", st.bottom);
	if (st.data)
		free(st.data);
	return (0);
}
