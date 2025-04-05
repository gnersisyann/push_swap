#include "../../../includes/stack.h"

static void	r_rotate(t_stack *stk)
{
	if (is_full(stk))
	{
		stk->top = stk->bottom;
		stk->bottom = next_up(stk, stk->bottom);
	}
	else
	{
		stk->top = next_up(stk, stk->top);
		stk->data[stk->top] = stk->data[stk->bottom];
		stk->data[stk->bottom] = 0;
		stk->bottom = next_up(stk, stk->bottom);
	}
}
void	r_rotate_a(t_push_swap *data)
{
	r_rotate(&data->a);
}
void	r_rotate_b(t_push_swap *data)
{
	r_rotate(&data->b);
}
void	r_rotate_ab(t_push_swap *data)
{
	r_rotate(&data->a);
	r_rotate(&data->b);
}
