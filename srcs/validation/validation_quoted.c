#include "../../includes/push_swap.h"

int	is_valid_quoted_numbers(char *str)
{
	int		i;
	int		space_found;
	char	*num_start;
	int		j;
	char	temp;
	int		*nums;
	int		count;

	i = 0;
	space_found = 0;
	while (str[i] && str[i] == ' ')
		i++;
	while (str[i])
	{
		if (ft_isdigit(str[i]) || (str[i] == '-' || str[i] == '+'))
		{
			if (i == 0 || space_found || str[i - 1] == ' ')
			{
				num_start = &str[i];
				j = 0;
				while (str[i + j] && str[i + j] != ' ')
					j++;
				temp = str[i + j];
				str[i + j] = '\0';
				if (!is_number(num_start) || !is_within_int_limits(num_start))
				{
					str[i + j] = temp;
					return (0);
				}
				str[i + j] = temp;
				i += j;
				space_found = 0;
			}
			else
				i++;
		}
		else if (str[i] == ' ')
		{
			space_found = 1;
			i++;
		}
		else
			return (0);
	}
	nums = extract_numbers_from_string(str, &count);
	if (!nums)
		return (0);
	if (has_duplicates(nums, count))
	{
		free(nums);
		return (0);
	}
	free(nums);
	return (1);
}
