#include "../../inc/tuples.h"

int	main(void)
{
	t_tuple	t;

	t = tuple(3.0, 2.0, 1.0, 0.0);
	print_tuple(t);
	return (0);
}
