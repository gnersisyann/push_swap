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
	if (argc == 1)
		exit(0);

	// Случай ./push_swap "1 2 3 4 5"
	if (argc == 2)
	{
		if (!is_valid_quoted_numbers(argv[1]))
			ft_error("Error");
		return (1);
	}

	// Случай ./push_swap 1 2 3 4 5
	// Проверка, что все аргументы - валидные числа
	if (!check_all_numbers(argc, argv))
		ft_error("Error");

	// Проверка, что все числа в пределах INT
	if (!check_int_limits_args(argc, argv))
		ft_error("Error");

	// Проверка на дубликаты
	if (check_duplicates_args(argc, argv))
		ft_error("Error");

	return (1);
}