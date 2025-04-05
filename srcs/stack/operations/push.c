#include "../../../includes/stack.h"

static void	push(t_stack *src, t_stack *dest)
{
	if (current_size(src) == 0)
		return ;
	dest->top = next_up(dest, dest->top);
	dest->data[dest->top] = src->data[src->top];
	if (current_size(dest) == 1)
		dest->bottom = dest->top;
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