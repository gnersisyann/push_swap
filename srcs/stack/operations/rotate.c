#include "../../../includes/stack.h"

static void	rotate(t_stack *stk)
{
	if (current_size(stk) < 2)
		return ;
	stk->top = next_down(stk, stk->top);
	stk->bottom = next_down(stk, stk->bottom);
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
