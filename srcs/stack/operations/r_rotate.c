#include "../../../includes/stack.h"

static void	r_rotate(t_stack *stk)
{
	if (current_size(stk) < 2)
		return ;
	stk->top = next_up(stk, stk->top);
	stk->bottom = next_up(stk, stk->bottom);
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
