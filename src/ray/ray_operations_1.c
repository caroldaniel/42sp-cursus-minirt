/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_operations_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:40:36 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/14 19:55:55 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	position(t_ray ray, double t)
{
	t_tuple	pos;
	t_tuple	mult;

	mult = tuple_multiply(ray.direction, t);
	pos = tuple_add(ray.origin, mult);
	return (pos);
}

t_ray	transform(t_ray r, t_matrix m)
{
	t_ray	t;
	t_tuple	origin_t;
	t_tuple	direction_t;

	origin_t = matrix_tuple_multiply(m, r.origin);
	direction_t = matrix_tuple_multiply(m, r.direction);
	t = ray(origin_t, direction_t);
	t.x_list = r.x_list;
	matrix_destroy(&m);
	return (t);
}

t_x	*hit(t_ray ray)
{
	t_x	*curr;

	curr = ray.x_list;
	if (!curr)
		return (NULL);
	while (curr)
	{
		if (curr->t < 0)
		{
			curr = curr->next;
			continue ;
		}
		return (curr);
	}
	return (NULL);
}
