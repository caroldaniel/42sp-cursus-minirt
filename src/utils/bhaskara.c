/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bhaskara.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 21:30:45 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 23:06:59 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_bhaskara	get_delta_sphere(t_ray *l_ray);
static t_bhaskara	get_delta_cylinder(t_ray *l_ray);
static t_bhaskara	get_delta_cone(t_ray *l_ray);

t_bhaskara	get_delta(t_object *object, t_ray *l_ray)
{
	t_bhaskara	_;

	_.a = 0.0;
	_.b = 0.0;
	_.c = 0.0;
	if (object->type == SPHERE)
		_ = get_delta_sphere(l_ray);
	if (object->type == CYLINDER)
		_ = get_delta_cylinder(l_ray);
	if (object->type == CONE)
		_ = get_delta_cone(l_ray);
	_.delta = pow(_.b, 2.0) - 4.0 * _.a * _.c;
	return (_);
}

static t_bhaskara	get_delta_sphere(t_ray *l_ray)
{
	t_bhaskara	_;
	t_tuple		sphere_to_ray;

	sphere_to_ray = tuple_subtract(l_ray->origin, point(0, 0, 0));
	_.a = dot(l_ray->direction, l_ray->direction);
	_.b = 2 * dot(l_ray->direction, sphere_to_ray);
	_.c = dot(sphere_to_ray, sphere_to_ray) - 1.0;
	return (_);
}

static t_bhaskara	get_delta_cylinder(t_ray *l_ray)
{
	t_bhaskara	_;

	_.a = pow(l_ray->direction.x, 2) + pow(l_ray->direction.z, 2);
	_.b = (2 * l_ray->origin.x * l_ray->direction.x) + \
		(2 * l_ray->origin.z * l_ray->direction.z);
	_.c = pow(l_ray->origin.x, 2) + pow(l_ray->origin.z, 2) - 1.0;
	return (_);
}

static t_bhaskara	get_delta_cone(t_ray *l_ray)
{
	t_bhaskara	_;

	_.a = pow(l_ray->direction.x, 2.0) - pow(l_ray->direction.y, 2.0) \
		+ pow(l_ray->direction.z, 2.0);
	_.b = (2 * l_ray->origin.x * l_ray->direction.x) - \
		(2 * l_ray->origin.y * l_ray->direction.y) + \
		(2 * l_ray->origin.z * l_ray->direction.z);
	_.c = pow(l_ray->origin.x, 2.0) - pow(l_ray->origin.y, 2.0) \
		+ pow(l_ray->origin.z, 2.0);
	return (_);
}
