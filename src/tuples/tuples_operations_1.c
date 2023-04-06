/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:41:47 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/06 18:35:25 by cado-car         ###   ########.fr       */
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

t_tuple	*tuple_multiply(t_tuple v, double scalar)
{
	t_tuple	*res;

	if (v.w == 1)
		return (NULL);
	res = tuple(v.x * scalar, v.y * scalar, v.z * scalar, 0.0);
	return (res);
}

t_tuple	*tuple_divide(t_tuple v, double scalar)
{
	t_tuple	*res;

	if (v.w == 1 || scalar == 0)
		return (NULL);
	res = tuple(v.x / scalar, v.y / scalar, v.z / scalar, 0.0);
	return (res);
}
