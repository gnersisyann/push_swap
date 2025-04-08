/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:05 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/08 14:50:46 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"
#include "../../includes/stack.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	int			stack_size;

	if (argc < 2)
		return (0);
	validate_input(argc, argv);
	stack_size = get_stack_size(argc, argv);
	init_stack(&ps.a, stack_size);
	init_stack(&ps.b, stack_size);
	ps.op_list = NULL;
	ps.checker_mode = 0;
	fill_stack(&ps.a, argc, argv);
	sort(&ps);
	optimize_operations(&ps, &ps.op_list);
	print_operations(ps.op_list);
	cleanup(&ps);
}
