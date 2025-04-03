#include "../../includes/stack.h"

int	count_numbers(char *str)
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
			in_number = 0;
		i++;
	}
	return (count);
}

int	get_next_number(char **str)
{
	int		num;
	char	*start;

	while (**str == ' ')
		(*str)++;
	start = *str;
	while (**str && **str != ' ')
		(*str)++;
	if (**str)
	{
		**str = '\0';
		num = ft_atoi(start);
		**str = ' ';
		(*str)++;
	}
	else
	{
		num = ft_atoi(start);
	}
	return (num);
}
