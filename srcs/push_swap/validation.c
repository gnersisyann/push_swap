#include "../../includes/push_swap.h"

static int	validate_input_helper(int argc, char **argv)
{
	int	*nums;
	int	i;
	int	j;

	nums = malloc(sizeof(int) * (argc - 1));
	if (!nums)
		ft_error("Error");
	i = 1;
	j = 0;
	while (i < argc)
	{
		nums[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}
	if (has_duplicates(nums, argc - 1))
	{
		free(nums);
		ft_error("Error");
	}
	free(nums);
	return (1);
}

int	validate_input(int argc, char **argv)
{
	int	i;
	int	*nums;
	int	j;

	if (argc == 2)
	{
		if (!is_valid_quoted_numbers(argv[1]))
			ft_error("Error");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		if (!is_number(argv[i]))
			ft_error("Error");
		i++;
	}
	return (validate_input_helper(argc, argv));
}
