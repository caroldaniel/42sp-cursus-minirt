/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:30:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 10:31:05 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	tuple(double x, double y, double z, double w)
{
	t_tuple	tuple;

	tuple.x = x;
	tuple.y = y;
	tuple.z = z;
	tuple.w = w;
	return (tuple);
}

t_tuple	point(double x, double y, double z)
{
	t_tuple	point;

	point = tuple(x, y, z, 1.0);
	return (point);
}

t_tuple	vector(double x, double y, double z)
{
	t_tuple	vector;

	vector = tuple(x, y, z, 0.0);
	return (vector);
}
