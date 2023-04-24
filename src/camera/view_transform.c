/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:51:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/23 22:05:41 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_matrix	calculate_transform(t_matrix *orientation, t_matrix *translate);

t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up)
{
	t_tuple		forward;
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	orientation;
	t_matrix	translate;

	forward = normalize(tuple_subtract(to, from));
	left = cross(forward, normalize(up));
	true_up = cross(left, forward);
	orientation = matrix_populate(4, left.x, left.y, left.z, 0, \
		true_up.x, true_up.y, true_up.z, 0, \
		-forward.x, -forward.y, -forward.z, 0, \
		0, 0, 0, 1);
	translate = translation(-from.x, -from.y, -from.z);
	return (calculate_transform(&orientation, &translate));
}

static t_matrix	calculate_transform(t_matrix *orientation, t_matrix *translate)
{
	t_matrix	result;

	result = matrix_multiply(*orientation, *translate);
	matrix_destroy(orientation);
	matrix_destroy(translate);
	return (result);
}
