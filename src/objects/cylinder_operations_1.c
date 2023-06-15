/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_operations_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:50:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 23:46:29 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		intersect_caps(t_object *cyl, t_ray *ray, t_ray *l_ray);

void	intersect_cylinder(t_object *cyl, t_ray *ray, t_ray *l_ray)
{
	t_bhaskara	_;
	double		t[2];

	intersect_caps(cyl, ray, l_ray);
	_ = get_delta(cyl, l_ray);
	if (comp(_.a, 0.0, EPSILON) || _.delta < 0)
		return ;
	t[0] = (-_.b - sqrt(_.delta)) / (2 * _.a);
	t[1] = (-_.b + sqrt(_.delta)) / (2 * _.a);
	truncate_object(cyl, ray, l_ray, fmin(t[0], t[1]));
	truncate_object(cyl, ray, l_ray, fmax(t[0], t[1]));
	return ;
}

static void	intersect_caps(t_object *cyl, t_ray *ray, t_ray *l_ray)
{
	double	t;

	if (!cyl->capped || comp(l_ray->direction.y, 0.0, EPSILON))
		return ;
	t = (cyl->minimum - l_ray->origin.y) / l_ray->direction.y;
	if (check_caps(l_ray, t, 1.0))
		x_list_add(&ray->x_list, x_new(cyl, t));
	t = (cyl->maximum - l_ray->origin.y) / l_ray->direction.y;
	if (check_caps(l_ray, t, 1.0))
		x_list_add(&ray->x_list, x_new(cyl, t));
	return ;
}

t_tuple	normal_at_cylinder(t_object *cyl, t_tuple p)
{
	double	dist;

	dist = pow(p.x, 2.0) + pow(p.z, 2.0);
	if (dist < 1 && (p.y >= (cyl->maximum - EPSILON)))
		return (vector(0, 1, 0));
	if (dist < 1 && (p.y <= (cyl->minimum + EPSILON)))
		return (vector(0, -1, 0));
	return (vector(p.x, 0, p.z));
}
