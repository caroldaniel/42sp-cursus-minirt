/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:30:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 09:53:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	*tuple(double x, double y, double z, short w)
{
	t_tuple	*tuple;

	tuple = malloc(sizeof(t_tuple));
	if (!tuple)
		return (NULL);
	tuple->x = x;
	tuple->y = y;
	tuple->z = z;
	tuple->w = w;
	return (tuple);
}

t_tuple	*point(double x, double y, double z)
{
	t_tuple	*point;

	point = tuple(x, y, z, 1.0);
	if (!point)
		return (NULL);
	return (point);
}

t_tuple	*vector(double x, double y, double z)
{
	t_tuple	*vector;

	vector = tuple(x, y, z, 0.0);
	if (!vector)
		return (NULL);
	return (vector);
}
