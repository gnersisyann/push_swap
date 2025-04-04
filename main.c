/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:05 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 16:24:26 by ganersis         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_push_swap	ps;
	int			stack_size;

	if (argc < 2)
		return (0);
	validate_input(argc, argv);
	// Определяем размер стека
	stack_size = get_stack_size(argc, argv);
	// Инициализируем стеки
	init_stack(&ps.a, stack_size);
	init_stack(&ps.b, stack_size);
	ps.op_list = NULL;
	// Заполняем стек A значениями из аргументов
	fill_stack(&ps.a, argc, argv);
	// Вывод данных для отладки
	printf("Стек A:\n");
	for (int i = 0; i < ps.a.size; ++i)
	{
		printf("%d ", ps.a.data[i]);
	}
	printf("\nРазмер: %d", ps.a.size);
	printf("\nВерх: %d", ps.a.top);
	printf("\nНиз: %d\n", ps.a.bottom);
	printf("\nСтек B (пустой):\n");
	printf("Размер: %d\n", ps.b.size);
	// Освобождаем память
	cleanup(&ps);
	return (0);
}
