#include "../../../includes/stack.h"

void	swap(t_stack *stk)
{
	int	tmp;

	if (stk->data[next_down(stk, stk->top)] == 0)
		return ;
	tmp = stk->data[next_down(stk, stk->top)];
	stk->data[next_down(stk, stk->top)] = stk->data[stk->top];
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