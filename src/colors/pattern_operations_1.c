/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:45:54 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 21:25:37 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_color	pattern_at_object(t_object *object, t_tuple world_point)
{
	t_matrix	obj_t_inv;
	t_matrix	pat_t_inv;
	t_tuple		object_point;
	t_tuple		pattern_point;

	obj_t_inv = matrix_inverse(object->transform);
	object_point = matrix_tuple_multiply(obj_t_inv, world_point);
	pat_t_inv = matrix_inverse(object->material.pattern.transform);
	pattern_point = matrix_tuple_multiply(pat_t_inv, object_point);
	matrix_destroy(&obj_t_inv);
	matrix_destroy(&pat_t_inv);
	return (pattern_at(object->material.pattern, pattern_point));
}

t_color	pattern_at(t_pattern pattern, t_tuple point)
{
	if (pattern.type == SOLID)
		return (pattern.a);
	if (pattern.type == STRIPE)
	{
		if (fmod(abs_float(point.x), 2.0) < 1.0)
			return (pattern.a);
		return (pattern.b);
	}
	if (pattern.type == CHECKER)
	{
		if (fmod(abs_float(point.x) + abs_float(point.y) + abs_float(point.z), \
			2.0) < 1.0)
			return (pattern.a);
		return (pattern.b);
	}
	return (color(0, 0, 0, 1));
}

void	set_pattern_transform(t_pattern *pattern, t_matrix t)
{
	matrix_destroy(&pattern->transform);
	pattern->transform = t;
}
