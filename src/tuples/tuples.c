/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 23:30:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/03 23:58:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple *tuple(float x, float y, float z, short w)
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

t_tuple *point(float x, float y, float z)
{
	t_tuple *point;

	point = tuple(x, y, z, 1.0);
	if (!point)
		return (NULL);
	return (point);
}

t_tuple *vector(float x, float y, float z)
{
	t_tuple *vector;

	vector = tuple(x, y, z, 0.0);
	if (!vector)
		return (NULL);
	return (vector);
}

void	print_tuple(t_tuple tuple)
{
	if (tuple.w == 1.0)
		printf("\nTuple is a point\n\n");
	else
		printf("\nTuple is a vector\n\n");
	printf("tuple.x = %.1f\n", tuple.x);
	printf("tuple.y = %.1f\n", tuple.y);
	printf("tuple.z = %.1f\n", tuple.z);
	printf("tuple.w = %.1f\n", tuple.w);
	return ;
}
