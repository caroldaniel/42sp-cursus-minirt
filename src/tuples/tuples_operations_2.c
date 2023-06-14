/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:38:09 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 17:19:54 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	magnitude(t_tuple v)
{
	double	mag;

	if (comp(v.w, 1, EPSILON))
		return (-1);
	mag = sqrt((pow(v.x, 2.0) + pow(v.y, 2.0) + pow(v.z, 2.0)));
	return (mag);
}

t_tuple	normalize(t_tuple v)
{
	t_tuple	nml;
	double	mag;

	mag = magnitude(v);
	if (mag <= 0.0)
		return (tuple(0, 0, 0, 0));
	nml = vector(v.x / mag, v.y / mag, v.z / mag);
	return (nml);
}

double	dot(t_tuple a, t_tuple b)
{
	double	pdt;

	if (comp(a.w, 1.0, EPSILON) || comp(b.w, 1.0, EPSILON))
		return (-1);
	pdt = a.x * b.x + a.y * b.y + a.z * b.z;
	return (pdt);
}

t_tuple	cross(t_tuple a, t_tuple b)
{
	t_tuple	v;

	if (comp(a.w, 1.0, EPSILON) || comp(b.w, 1.0, EPSILON))
		return (tuple(0, 0, 0, 0));
	v = vector(a.y * b.z - a.z * b.y, \
		a.z * b.x - a.x * b.z, \
		a.x * b.y - a.y * b.x);
	return (v);
}
