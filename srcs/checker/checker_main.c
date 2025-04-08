#include "../../includes/push_swap.h"
#include <unistd.h>

void	err(void)
{
	ft_putstr_fd("Error\n", 1);
	exit(1);
}

int	main(int argc, char **argv)
{
	int			stack_size;
	t_push_swap	ps;
	char		buf[BUFSIZE + 1];
	char		*op_arr;
	char		*op_arr_orig;
	int			read_bytes;
	char		*temp;
	int			step;

	if (argc < 2)
		err();
	validate_input(argc, argv);
	stack_size = get_stack_size(argc, argv);
	init_stack(&ps.a, stack_size);
	init_stack(&ps.b, stack_size);
	ps.op_list = NULL;
	ps.checker_mode = 1;
	op_arr = ft_strdup("");
	op_arr_orig = op_arr;
	fill_stack(&ps.a, argc, argv);
	while ((read_bytes = read(0, buf, BUFSIZE)) > 0)
	{
		buf[read_bytes] = '\0';
		temp = ft_strjoin(op_arr, buf);
		if (!temp)
		{
			free(op_arr_orig);
			err();
		}
		op_arr = temp;
	}
	if (read_bytes < 0)
	{
		free(op_arr_orig);
		err();
	}
	while (*op_arr)
	{
		step = 3;
		if (ft_strncmp(op_arr, "pa", 2) == 0)
			push_a(&ps);
		else if (ft_strncmp(op_arr, "pb", 2) == 0)
			push_b(&ps);
		else if (ft_strncmp(op_arr, "sa", 2) == 0)
			swap_a(&ps);
		else if (ft_strncmp(op_arr, "sb", 2) == 0)
			swap_b(&ps);
		else if (ft_strncmp(op_arr, "ss", 2) == 0)
			swap_ab(&ps);
		else if (ft_strncmp(op_arr, "rra", 3) == 0)
		{
			r_rotate_a(&ps);
			++step;
		}
		else if (ft_strncmp(op_arr, "rrb", 3) == 0)
		{
			r_rotate_b(&ps);
			++step;
		}
		else if (ft_strncmp(op_arr, "rrr", 3) == 0)
		{
			r_rotate_ab(&ps);
			++step;
		}
		else if (ft_strncmp(op_arr, "ra", 2) == 0)
			rotate_a(&ps);
		else if (ft_strncmp(op_arr, "rb", 2) == 0)
			rotate_b(&ps);
		else if (ft_strncmp(op_arr, "rr", 2) == 0)
			rotate_ab(&ps);
		op_arr += step;
	}
	free(op_arr_orig);
	if (is_sorted(&ps))
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
}
