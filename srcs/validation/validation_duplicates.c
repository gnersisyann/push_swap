#include "../../includes/push_swap.h"

int	has_duplicates(int *nums, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nums[i] == nums[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_duplicates_args(int argc, char **argv)
{
	int *nums;
	int i;
	int j;
	int result;

	nums = malloc(sizeof(int) * (argc - 1));
	if (!nums)
		return (1);

	i = 1;
	j = 0;
	while (i < argc)
	{
		nums[j] = ft_atoi(argv[i]);
		i++;
		j++;
	}

	result = has_duplicates(nums, argc - 1);
	free(nums);
	return (result);
}