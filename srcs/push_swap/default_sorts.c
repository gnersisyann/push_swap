#include "../../includes/push_swap.h"

int	down_distance_to_top(t_stack *st, int idx)
{
	int	dist;

	dist = 0;
	while (idx != st->top)
	{
		++dist;
		idx = next_down(st, idx);
	}
	return (dist);
}

int	up_distance_to_top(t_stack *st, int idx)
{
	int	dist;

	dist = 0;
	while (idx != st->top)
	{
		++dist;
		idx = next_up(st, idx);
	}
	return (dist);
}
void	bring_min_to_top(t_push_swap *ps)
{
	int	idx;
	int	min_idx;
	int	min_val;
	int	i;
	int	count;

	i = 0;
	count = current_size(&ps->a);
	if (count <= 1)
		return ;
	min_idx = ps->a.top;
	min_val = ps->a.data[ps->a.top];
	idx = next_down(&ps->a, ps->a.top);
	count--;
	while (count > 0)
	{
		if (ps->a.data[idx] < min_val)
		{
			min_val = ps->a.data[idx];
			min_idx = idx;
		}
		idx = next_down(&ps->a, idx);
		count--;
	}
	if (up_distance_to_top(&ps->a, min_idx) < down_distance_to_top(&ps->a,
			min_idx))
		while (i++ < up_distance_to_top(&ps->a, min_idx))
			rotate_a(ps);
	else
		while (i++ < down_distance_to_top(&ps->a, min_idx))
			r_rotate_a(ps);
}

void	sort_3(t_push_swap *ps)
{
	int	top_idx;
	int	mid_idx;
	int	bot_idx;

	top_idx = ps->a.top;
	mid_idx = next_down(&ps->a, top_idx);
	bot_idx = next_down(&ps->a, mid_idx);
	if (ps->a.data[top_idx] > ps->a.data[mid_idx]
		&& ps->a.data[mid_idx] > ps->a.data[bot_idx])
		return (swap_a(ps), r_rotate_a(ps));
	if (ps->a.data[top_idx] > ps->a.data[bot_idx]
		&& ps->a.data[bot_idx] > ps->a.data[mid_idx])
		return (rotate_a(ps));
	if (ps->a.data[mid_idx] > ps->a.data[top_idx]
		&& ps->a.data[top_idx] > ps->a.data[bot_idx])
		return (r_rotate_a(ps));
	if (ps->a.data[bot_idx] > ps->a.data[top_idx]
		&& ps->a.data[top_idx] > ps->a.data[mid_idx])
		return (swap_a(ps));
	if (ps->a.data[mid_idx] > ps->a.data[bot_idx]
		&& ps->a.data[bot_idx] > ps->a.data[top_idx])
		return (swap_a(ps), rotate_a(ps));
}

void	sort_4_5(t_push_swap *ps)
{
	int	count;

	count = current_size(&ps->a);
	if (count == 4)
	{
		bring_min_to_top(ps);
		push_b(ps);
		sort_3(ps);
		push_a(ps);
		return ;
	}
	bring_min_to_top(ps);
	push_b(ps);
	bring_min_to_top(ps);
	push_b(ps);
	sort_3(ps);
	push_a(ps);
	push_a(ps);
}

/*
5
4
3
2   2
1   1

*/