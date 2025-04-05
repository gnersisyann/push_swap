#include "../../../includes/stack.h"

static void	rotate(t_stack *stk)
{
	if (is_full(stk))
	{
		stk->bottom = stk->top;
		stk->top = next_down(stk, stk->top);
	}
	else
	{
		stk->bottom = next_down(stk, stk->bottom);
		stk->data[stk->bottom] = stk->data[stk->top];
		stk->data[stk->top] = 0;
		stk->top = next_down(stk, stk->top);
	}
}
void	rotate_a(t_push_swap *data)
{
	rotate(&data->a);
}
void	rotate_b(t_push_swap *data)
{
	rotate(&data->b);
}
void	rotate_ab(t_push_swap *data)
{
	rotate(&data->a);
	rotate(&data->b);
}
