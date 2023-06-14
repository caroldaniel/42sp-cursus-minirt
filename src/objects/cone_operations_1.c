/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone_operations_1.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 16:16:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 19:25:17 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	*calculate_coef(t_ray *l_ray);
static void		intersect_caps(t_object *cone, t_ray *ray, t_ray *l_ray);
static bool		check_caps(t_ray *l_ray, double t, double radius);

void	intersect_cone(t_object *cone, t_ray *ray, t_ray *l_ray)
{
	double	*coef;
	double	disc;
	double	t[2];
	double	y;

	coef = calculate_coef(l_ray);
	if (comp(coef[0], 0.0, EPSILON) && !comp(coef[1], 0.0, EPSILON))
	{
		t[0] = -coef[2] / (2 * coef[1]);
		y = l_ray->origin.y + t[0] * l_ray->direction.y;
		if (cone->minimum < y && y < cone->maximum)
			x_list_add(&ray->x_list, x_new(cone, t[0]));
	}
	if (!comp(coef[0], 0.0, EPSILON))
	{
		disc = pow(coef[1], 2.0) - 4.0 * coef[0] * coef[2];
		if (disc >= 0)
		{
			t[0] = (-coef[1] - sqrt(disc)) / (2 * coef[0]);
			t[1] = (-coef[1] + sqrt(disc)) / (2 * coef[0]);
			truncate_object(cone, ray, l_ray, t);
		}
	}
	intersect_caps(cone, ray, l_ray);
	return ;
}

static double	*calculate_coef(t_ray *l_ray)
{
	static double	coef[3];

	coef[0] = pow(l_ray->direction.x, 2) - pow(l_ray->direction.y, 2) \
		+ pow(l_ray->direction.z, 2);
	coef[1] = (2 * l_ray->origin.x * l_ray->direction.x) - \
		(2 * l_ray->origin.y * l_ray->direction.y) + \
		(2 * l_ray->origin.z * l_ray->direction.z);
	coef[2] = pow(l_ray->origin.x, 2) - pow(l_ray->origin.y, 2) \
		+ pow(l_ray->origin.z, 2);
	return (coef);
}

static void	intersect_caps(t_object *cone, t_ray *ray, t_ray *l_ray)
{
	double	t;

	if (!cone->capped || comp(l_ray->direction.y, 0.0, EPSILON))
		return ;
	t = (cone->minimum - l_ray->origin.y) / l_ray->direction.y;
	if (check_caps(l_ray, t, fabs(cone->minimum)))
		x_list_add(&ray->x_list, x_new(cone, t));
	t = (cone->maximum - l_ray->origin.y) / l_ray->direction.y;
	if (check_caps(l_ray, t, fabs(cone->maximum)))
		x_list_add(&ray->x_list, x_new(cone, t));
	return ;
}

static bool	check_caps(t_ray *l_ray, double t, double radius)
{
	double	x;
	double	z;

	x = l_ray->origin.x + t * l_ray->direction.x;
	z = l_ray->origin.z + t * l_ray->direction.z;
	if (pow(x, 2.0) + pow(z, 2.0) <= radius)
		return (true);
	return (false);
}

t_tuple	normal_at_cone(t_object *cone, t_tuple p)
{
	double	dist;
	double	y;

	dist = pow(p.x, 2.0) + pow(p.z, 2.0);
	if (dist < 1 && (p.y >= (cone->maximum - EPSILON)))
		return (vector(0, 1, 0));
	if (dist < 1 && (p.y <= (cone->minimum + EPSILON)))
		return (vector(0, -1, 0));
	y = sqrt(pow(p.x, 2.0) + pow(p.z, 2.0));
	if (y > 0)
		y *= -1;
	return (vector(p.x, y, p.z));
}
