/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:41:47 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/04 21:46:17 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	*tuple_add(t_tuple a, t_tuple b)
{
	t_tuple	*sum;

	if ((a.w + b.w) > 1)
		return (NULL);
	sum = tuple(a.x + b.x, a.y + b.y, a.z + b.z, a.w + b.w);
	return (sum);
}

t_tuple	*tuple_subtract(t_tuple a, t_tuple b)
{
	t_tuple	*sub;

	if ((a.w - b.w) < 0)
		return (NULL);
	sub = tuple(a.x - b.x, a.y - b.y, a.z - b.z, a.w - b.w);
	return (sub);
}

t_tuple	*tuple_negate(t_tuple a)
{
	t_tuple	*neg;
	t_tuple	*zero;

	if (a.w == 1)
		return (NULL);
	zero = vector(0, 0, 0);
	neg = tuple_subtract(*zero, a);
	free(zero);
	return (neg);
}
