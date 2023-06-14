/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:49:57 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 19:22:18 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
	if (o->type == PLANE)
		o_nml = normal_at_plane(o, o_p);
	if (o->type == CYLINDER)
		o_nml = normal_at_cylinder(o, o_p);
	if (o->type == CONE)
		o_nml = normal_at_cone(o, o_p);
	trs = matrix_transpose(inv);
	nml = matrix_tuple_multiply(trs, o_nml);
	nml.w = 0;
	matrix_destroy(&inv);
	matrix_destroy(&trs);
	return (normalize(nml));
}

void	set_object_transform(t_object *object, t_matrix t)
{
	matrix_destroy(&object->transform);
	object->transform = t;
	return ;
}

void	truncate_object(t_object *obj, t_ray *ray, t_ray *l_ray, double *t)
{
	double	y[2];
	
	y[0] = l_ray->origin.y + fmin(t[0], t[1]) * l_ray->direction.y;
	if (obj->minimum < y[0] && y[0] < obj->maximum)
		x_list_add(&ray->x_list, x_new(obj, fmin(t[0], t[1])));
	y[1] = l_ray->origin.y + fmin(t[0], t[1]) * l_ray->direction.y;
	if (obj->minimum < y[1] && y[1] < obj->maximum)
		x_list_add(&ray->x_list, x_new(obj, fmin(t[0], t[1])));
	return ;
}
