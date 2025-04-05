/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:05 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 20:14:33 by ganersis         ###   ########.fr       */
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
	if (ps->a.data)
		free(ps->a.data);
	if (ps->b.data)
		free(ps->b.data);
}

// Отладочная функция для вывода содержимого стека
void	debug_stack(t_stack *stk, const char *name)
{
	int	idx;
	int	i;
	int	curr_size;

	curr_size = current_size(stk);
	printf("Стек %s:\n", name);
	printf("Размер массива: %d, Текущее кол-во элементов: %d\n", stk->size,
		curr_size);
	printf("Top index: %d, Top value: %d\n", stk->top, stk->data[stk->top]);
	printf("Bottom index: %d, Bottom value: %d\n", stk->bottom,
		stk->data[stk->bottom]);
	printf("Элементы (по порядку от top): ");
	if (curr_size > 0)
	{
		idx = stk->top;
		i = 0;
		while (i < curr_size)
		{
			printf("%d ", stk->data[idx]);
			idx = next_down(stk, idx);
			i++;
		}
	}
	else
	{
		printf("(пусто)");
	}
	printf("\n\n");
}

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
	fill_stack(&ps.a, argc, argv);
	// // Отладочная информация перед сортировкой
	// printf("=== ПЕРЕД СОРТИРОВКОЙ ===\n");
	// debug_stack(&ps.a, "A");
	// debug_stack(&ps.b, "B");
	// // Вызов сортировки
	// sort_4_5(&ps);
	// // Отладочная информация после сортировки
	// printf("=== ПОСЛЕ СОРТИРОВКИ ===\n");
	// debug_stack(&ps.a, "A");
	// debug_stack(&ps.b, "B");
	cleanup(&ps);
	return (0);
}
