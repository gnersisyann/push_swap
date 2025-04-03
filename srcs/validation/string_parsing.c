#include "../../includes/push_swap.h"

/**
 * @brief Подсчитывает количество чисел в строке, разделенных пробелами
 *
 * @param str Строка с числами
 * @return int Количество чисел
 */
int	count_numbers_in_string(char *str)
{
	int	i;
	int	count;
	int	in_number;

	i = 0;
	count = 0;
	in_number = 0;
	while (str[i])
	{
		if (str[i] != ' ' && !in_number)
		{
			in_number = 1;
			count++;
		}
		else if (str[i] == ' ')
		{
			in_number = 0;
		}
		i++;
	}
	return (count);
}

/**
 * @brief Извлекает числа из строки в массив
 *
 * @param str Строка с числами
 * @param count Указатель для сохранения количества извлеченных чисел
 * @return int* Массив извлеченных чисел или NULL при ошибке
 */
int	*extract_numbers_from_string(char *str, int *count)
{
	int *nums;
	int i;
	int num_count;
	char *tmp;
	char *tmp_ptr;
	char *start;
	int j;
	char temp;

	num_count = count_numbers_in_string(str);
	*count = num_count;
	if (num_count == 0)
		return (NULL);
	nums = malloc(sizeof(int) * num_count);
	if (!nums)
		return (NULL);
	tmp = ft_strdup(str);
	if (!tmp)
	{
		free(nums);
		return (NULL);
	}
	tmp_ptr = tmp;
	i = 0;
	while (i < num_count)
	{
		while (*tmp_ptr == ' ')
			tmp_ptr++;
		start = tmp_ptr;
		j = 0;
		while (tmp_ptr[j] && tmp_ptr[j] != ' ')
			j++;
		temp = tmp_ptr[j];
		tmp_ptr[j] = '\0';
		nums[i] = ft_atoi(start);
		tmp_ptr[j] = temp;
		tmp_ptr += j;
		i++;
	}
	free(tmp);
	return (nums);
}