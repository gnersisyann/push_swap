/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_main.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ganersis <ganersis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 15:46:14 by ganersis          #+#    #+#             */
/*   Updated: 2025/04/04 15:54:16 by ganersis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

/**
 * @brief Основная функция валидации входных аргументов
 *
 * @param argc Количество аргументов
 * @param argv Массив строк аргументов
 * @return int 1, если ввод корректен, иначе вызывает ft_error
 */
int	validate_input(int argc, char **argv)
{
	int	i;

	if (!argv)
		ft_error("Error");
	if (argc == 1)
		exit(0);
	i = 1;
	while (i < argc)
	{
		if (!argv[i] || !*argv[i])
			ft_error("Error");
		i++;
	}
	if (argc == 2)
	{
		if (!is_valid_quoted_numbers(argv[1]))
			ft_error("Error");
		return (1);
	}
	if (!check_all_numbers(argc, argv) || !check_int_limits_args(argc, argv)
		|| check_duplicates_args(argc, argv))
		ft_error("Error");
	return (1);
}
