/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view_transform.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 13:51:25 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 11:58:40 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_matrix	view_transform(t_tuple position, t_tuple forward, t_tuple up)
{
	t_tuple		left;
	t_tuple		true_up;
	t_matrix	orientation;
	t_matrix	translate;
	t_matrix	result;

	left = cross(forward, normalize(up));
	true_up = cross(left, forward);
	orientation = matrix_populate(4, left.x, left.y, left.z, 0.0, \
		true_up.x, true_up.y, true_up.z, 0.0, \
		-forward.x, -forward.y, -forward.z, 0.0, \
		0.0, 0.0, 0.0, 1.0);
	translate = translation(-position.x, -position.y, -position.z);
	result = matrix_multiply(orientation, translate);
	matrix_destroy(&orientation);
	matrix_destroy(&translate);
	return (result);
}
