/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:49:57 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/16 09:56:58 by cado-car         ###   ########.fr       */
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
	return (perturb_normal(normalize(nml), p, o->material));
}

void	set_object_transform(t_object *object, t_matrix t)
{
	matrix_destroy(&object->transform);
	object->transform = t;
	return ;
}

void	truncate_object(t_object *obj, t_ray *ray, t_ray *l_ray, double t)
{
	double	y;

	y = l_ray->origin.y + t * l_ray->direction.y;
	if (obj->minimum < y && y < obj->maximum)
		x_list_add(&ray->x_list, x_new(obj, t));
	return ;
}

bool	check_caps(t_ray *l_ray, double t, double radius)
{
	double	x;
	double	z;

	x = l_ray->origin.x + t * l_ray->direction.x;
	z = l_ray->origin.z + t * l_ray->direction.z;
	if (pow(x, 2.0) + pow(z, 2.0) <= pow(radius, 2.0))
		return (true);
	return (false);
}
