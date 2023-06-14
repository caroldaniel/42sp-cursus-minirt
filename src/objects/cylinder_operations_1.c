/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_operations_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:50:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 19:24:49 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static double	*calculate_coef(t_ray *l_ray);
static void		intersect_caps(t_object *cyl, t_ray *ray, t_ray *l_ray);
static bool		check_caps(t_ray *l_ray, double t);

void	intersect_cylinder(t_object *cyl, t_ray *ray, t_ray *l_ray)
{
	double	*coef;
	double	disc;
	double	t[2];

	coef = calculate_coef(l_ray);
	if (!comp(coef[0], 0.0, EPSILON))
	{
		disc = pow(coef[1], 2.0) - 4.0 * coef[0] * coef[2];
		if (disc >= 0)
		{
			t[0] = (-coef[1] - sqrt(disc)) / (2 * coef[0]);
			t[1] = (-coef[1] + sqrt(disc)) / (2 * coef[0]);
			truncate_object(cyl, ray, l_ray, t);
		}
	}
	intersect_caps(cyl, ray, l_ray);
	return ;
}

static double	*calculate_coef(t_ray *l_ray)
{
	static double	coef[3];

	coef[0] = pow(l_ray->direction.x, 2) + pow(l_ray->direction.z, 2);
	coef[1] = (2 * l_ray->origin.x * l_ray->direction.x) + \
		(2 * l_ray->origin.z * l_ray->direction.z);
	coef[2] = pow(l_ray->origin.x, 2) + pow(l_ray->origin.z, 2) - 1.0;
	return (coef);
}

static void	intersect_caps(t_object *cyl, t_ray *ray, t_ray *l_ray)
{
	double	t;

	if (!cyl->capped || comp(l_ray->direction.y, 0.0, EPSILON))
		return ;
	t = (cyl->minimum - l_ray->origin.y) / l_ray->direction.y;
	if (check_caps(l_ray, t))
		x_list_add(&ray->x_list, x_new(cyl, t));
	t = (cyl->maximum - l_ray->origin.y) / l_ray->direction.y;
	if (check_caps(l_ray, t))
		x_list_add(&ray->x_list, x_new(cyl, t));
	return ;	
}

static bool	check_caps(t_ray *l_ray, double t)
{
	double	x;
	double	z;

	x = l_ray->origin.x + t * l_ray->direction.x;
	z = l_ray->origin.z + t * l_ray->direction.z;
	if (pow(x, 2.0) + pow(z, 2.0) <= 1)
		return (true);
	return (false);
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
