/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pattern_operations_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 20:45:54 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 14:40:03 by cado-car         ###   ########.fr       */
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
	matrix_destroy(&obj_t_inv);
	pat_t_inv = matrix_inverse(object->material.pattern.transform);
	pattern_point = matrix_tuple_multiply(pat_t_inv, object_point);
	matrix_destroy(&pat_t_inv);
	return (pattern_at(object->material.pattern, pattern_point));
}

t_color	pattern_at(t_pattern pattern, t_tuple p)
{
	if (pattern.type == SOLID)
		return (pattern.a);
	if (pattern.type == STRIPE)
		if (((int)floor(p.x)) % 2 == 0)
			return (pattern.a);
	if (pattern.type == CHECKER)
		if (((int)floor(p.x) + (int)floor(p.y) + (int)floor(p.z)) % 2 == 0)
			return (pattern.a);
	return (pattern.b);
}

void	set_pattern_transform(t_pattern *pattern, t_matrix t)
{
	matrix_destroy(&pattern->transform);
	pattern->transform = t;
}
