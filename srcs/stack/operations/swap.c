#include "../../../includes/stack.h"

static void	swap(t_stack *stk)
{
	int	idx;
	int	tmp;

	if (current_size(stk) < 2)
		return ;
	idx = next_down(stk, stk->top);
	tmp = stk->data[idx];
	stk->data[idx] = stk->data[stk->top];
	stk->data[stk->top] = tmp;
}

void	swap_a(t_push_swap *data)
{
	swap(&data->a);
}

void	swap_b(t_push_swap *data)
{
	swap(&data->b);
}

void	swap_ab(t_push_swap *data)
{
	swap(&data->a);
	swap(&data->b);
}