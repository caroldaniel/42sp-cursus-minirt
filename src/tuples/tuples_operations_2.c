/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_operations_2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 09:38:09 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 14:58:35 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	magnitude(t_tuple v)
{
	double mag;
	
	if (v.w == 1)
		return (-1);
	mag = sqrt((pow(v.x, 2.0) + pow(v.y, 2.0) + pow(v.z, 2.0)));
	return (mag);
}

t_tuple *normalize(t_tuple v)
{
	t_tuple	*nml;
	double	mag;

	mag = magnitude(v);
	if (mag <= 0.0)
		return (NULL);
	nml = vector(v.x / mag, v.y / mag, v.z / mag);
	return (nml);
}

double	dot(t_tuple a, t_tuple b)
{
	double	pdt;

	if (a.w == 1 || b.w == 1)
		return (-1);
	pdt = a.x * b.x + a.y * b.y + a.z * b.z;
	return (pdt);
}

t_tuple *cross(t_tuple a, t_tuple b)
{
	t_tuple	*v;

	if (a.w == 1 || b.w == 1)
		return (NULL);
	v = vector(a.y * b.z - a.z * b.y, \
		a.z * b.x - a.x * b.z, \
		a.x * b.y - a.y * b.x);
	return (v);
}
