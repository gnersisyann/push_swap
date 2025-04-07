/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:05 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/07 18:14:54 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"
#include "includes/stack.h"
#include <stdio.h>

static int	get_stack_size(int argc, char **argv)
{
	if (argc == 2)
		return (count_numbers(argv[1]));
	return (argc - 1);
}

static void	cleanup(t_push_swap *ps)
{
	t_list	*tmp;

	if (ps->a.data)
		free(ps->a.data);
	if (ps->b.data)
		free(ps->b.data);
	while (ps->op_list)
	{
		tmp = ps->op_list->next;
		free(ps->op_list->content); // Освобождаем содержимое узла
		free(ps->op_list);          // Освобождаем сам узел
		ps->op_list = tmp;
	}
}

int	main(int argc, char **argv)
{
	t_push_swap		ps;
	int				stack_size;
	t_list			*op;
	t_operations	*operation;

	if (argc < 2)
		return (0);
	validate_input(argc, argv);
	stack_size = get_stack_size(argc, argv);
	init_stack(&ps.a, stack_size);
	init_stack(&ps.b, stack_size);
	ps.op_list = NULL;
	fill_stack(&ps.a, argc, argv);
	sort(&ps);
	op = ps.op_list;
	while (op)
	{
		operation = (t_operations *)(op->content);
		printf("%s\n", operation_to_string(*operation));
		op = op->next;
	}
	cleanup(&ps);
}
