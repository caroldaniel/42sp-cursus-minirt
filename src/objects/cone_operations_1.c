/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:16:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 23:45:57 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void		intersect_caps(t_object *cone, t_ray *ray, t_ray *l_ray);

void	intersect_cone(t_object *cone, t_ray *ray, t_ray *l_ray)
{
	t_bhaskara	_;
	double		t[2];

	intersect_caps(cone, ray, l_ray);
	_ = get_delta(cone, l_ray);
	if ((comp(_.a, 0.0, EPSILON) && comp(_.b, 0.0, EPSILON)) || _.delta < 0)
		return ;
	if (comp(_.a, 0.0, EPSILON))
		return (truncate_object(cone, ray, l_ray, (-_.c) / (2 * _.b)));
	t[0] = (-_.b - sqrt(_.delta)) / (2 * _.a);
	t[1] = (-_.b + sqrt(_.delta)) / (2 * _.a);
	truncate_object(cone, ray, l_ray, fmin(t[0], t[1]));
	truncate_object(cone, ray, l_ray, fmax(t[0], t[1]));
	return ;
}

static void	intersect_caps(t_object *cone, t_ray *ray, t_ray *l_ray)
{
	double	t;

	if (!cone->capped || comp(l_ray->direction.y, 0.0, EPSILON))
		return ;
	t = (cone->minimum - l_ray->origin.y) / l_ray->direction.y;
	if (check_caps(l_ray, t, cone->minimum))
		x_list_add(&ray->x_list, x_new(cone, t));
	t = (cone->maximum - l_ray->origin.y) / l_ray->direction.y;
	if (check_caps(l_ray, t, cone->maximum))
		x_list_add(&ray->x_list, x_new(cone, t));
	return ;
}

t_tuple	normal_at_cone(t_object *cone, t_tuple p)
{
	double	dist;
	double	y;

	dist = pow(p.x, 2.0) + pow(p.z, 2.0);
	if (dist < pow(cone->maximum, 2.0) && (p.y >= (cone->maximum - EPSILON)))
		return (vector(0, 1, 0));
	if (dist < pow(cone->minimum, 2.0) && (p.y <= (cone->minimum + EPSILON)))
		return (vector(0, -1, 0));
	y = sqrt(dist);
	if (p.y > 0)
		y *= -1;
	return (vector(p.x, y, p.z));
}
