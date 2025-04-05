#include "../includes/stack.h"

int	current_size(t_stack *stk)
{
	if (!stk->data || (stk->top == stk->bottom && stk->data[stk->top] == 0))
		return (0);
	if (stk->top == stk->bottom)
		return (1);
	if (stk->top > stk->bottom)
		return ((stk->size - stk->top) + stk->bottom + 1);
	else
		return (stk->bottom - stk->top + 1);
}
int	next_up(t_stack *stack, int idx)
{
	if (current_size(stack) == 0)
		return (idx);
	if (idx == 0)
		return (stack->size - 1);
	else
		return (idx - 1);
}

int	next_down(t_stack *stack, int idx)
{
	if (current_size(stack) == 0)
		return (idx);
	if (idx == stack->size - 1)
		return (0);
	else
		return (idx + 1);
}