#include "../../../includes/stack.h"

const char	*operation_to_string(t_operations op)
{
	if (op == sa)
		return ("sa");
	if (op == sb)
		return ("sb");
	if (op == ss)
		return ("ss");
	if (op == pa)
		return ("pa");
	if (op == pb)
		return ("pb");
	if (op == ra)
		return ("ra");
	if (op == rb)
		return ("rb");
	if (op == rr)
		return ("rr");
	if (op == rra)
		return ("rra");
	if (op == rrb)
		return ("rrb");
	if (op == rrr)
		return ("rrr");
	return (NULL);
}