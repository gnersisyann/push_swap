#include "../../../includes/stack.h"

void	push(t_stack *src, t_stack *dest)
{
	int	dest_i;

	if (is_full(dest))
		return ;
	dest_i = next_up(dest, dest->top);
	dest->data[dest_i] = src->data[src->top];
	dest->top = dest_i;
	src->data[src->top] = 0;
	src->top = next_down(src, src->top);
}

void	push_a(t_push_swap *data)
{
	push(&data->b, &data->a);
}

void	push_b(t_push_swap *data)
{
	push(&data->a, &data->b);
}