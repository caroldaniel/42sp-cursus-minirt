/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:49:57 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/05 12:33:27 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_object *object, t_matrix t)
{
	matrix_destroy(&object->transform);
	object->transform = t;
}

t_tuple	normal_at(t_object *o, t_tuple p)
{
	t_matrix	inv;
	t_matrix	trs;
	t_tuple		o_p;
	t_tuple		o_nml;
	t_tuple		nml;

	inv = matrix_inverse(o->transform);
	o_p = matrix_tuple_multiply(inv, p);
	if (o->type == SPHERE)
		o_nml = normal_at_sphere(o, o_p);
	else if (o->type == PLANE)
		o_nml = normal_at_plane(o, o_p);
	else if (o->type == CYLINDER)
		o_nml = normal_at_cylinder(o, o_p);
	else
		o_nml = tuple(0, 0, 0, 0);
	trs = matrix_transpose(inv);
	nml = matrix_tuple_multiply(trs, o_nml);
	nml.w = 0;
	matrix_destroy(&inv);
	matrix_destroy(&trs);
	return (normalize(nml));
}
