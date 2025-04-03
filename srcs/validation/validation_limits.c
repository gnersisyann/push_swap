#include "../../includes/push_swap.h"
#include <limits.h>

/**
 * @brief Проверяет, находится ли строковое представление числа в пределах INT
 *
 * @param str Строка для проверки
 * @return int 1, если число в пределах INT, 0 в противном случае
 */
int	is_within_int_limits(char *str)
{
	long	num;
	int		sign;
	int		i;

	num = 0;
	sign = 1;
	i = 0;
	// Проверка знака
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	// Преобразование в число и проверка переполнения
	while (str[i] && ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		// Проверка на выход за пределы INT
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num
				* sign < INT_MIN))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Проверяет, находятся ли все аргументы в пределах INT
 *
 * @param argc Количество аргументов
 * @param argv Массив строк аргументов
 * @return int 1, если все числа в пределах INT, 0 в противном случае
 */
int	check_int_limits_args(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (!is_within_int_limits(argv[i]))
			return (0);
		i++;
	}
	return (1);
}

/**
 * @brief Проверяет, находятся ли все числа из строки в пределах INT
 *
 * @param str Строка с числами, разделенными пробелами
 * @return int 1, если все числа в пределах INT, 0 в противном случае
 */
int	check_int_limits_string(char *str)
{
	int i;
	int j;
	char *num_start;
	char temp;

	i = 0;
	while (str[i])
	{
		// Пропускаем пробелы
		while (str[i] && str[i] == ' ')
			i++;

		if (str[i])
		{
			// Находим конец числа
			num_start = &str[i];
			j = 0;
			while (str[i + j] && str[i + j] != ' ')
				j++;

			// Временно заменяем пробел на '\0'
			temp = str[i + j];
			str[i + j] = '\0';

			// Проверяем пределы
			if (!is_within_int_limits(num_start))
			{
				str[i + j] = temp;
				return (0);
			}

			str[i + j] = temp;
			i += j;
		}
	}

	return (1);
}