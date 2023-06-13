/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_operations_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:50:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/06 18:42:33 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_cylinder_x(t_ray *ray, t_ray *l_ray, t_object *cyl, double *t);
static void	intersect_caps(t_ray *ray, t_ray *l_ray, t_object *cyl);

void	intersect_cylinder(t_object *cyl, t_ray *ray, t_ray *local_ray)
{
	double		coef[3];
	double		disc;
	double		t[2];

	coef[0] = pow(local_ray->direction.x, 2) + pow(local_ray->direction.z, 2);
	if (float_cmp(coef[0], 0.0, EPSILON))
		return ;
	coef[1] = (2 * local_ray->origin.x * local_ray->direction.x) + \
		(2 * local_ray->origin.z * local_ray->direction.z);
	coef[2] = pow(local_ray->origin.x, 2) + pow(local_ray->origin.z, 2) - 1.0;
	disc = pow(coef[1], 2.0) - 4.0 * coef[0] * coef[2];
	if (disc < 0)
		return ;
	t[0] = (-coef[1] - sqrt(disc)) / (2 * coef[0]);
	t[1] = (-coef[1] + sqrt(disc)) / (2 * coef[0]);
	if (t[0] > t[1])
		swap_doubles(&t[0], &t[1]);
	add_cylinder_x(ray, local_ray, cyl, t);
	return ;
}

static void	add_cylinder_x(t_ray *ray, t_ray *l_ray, t_object *cyl, double *t)
{
	double	y0;
	double	y1;

	y0 = l_ray->origin.y + t[0] * l_ray->direction.y;
	if (cyl->minimum < y0 && y0 < cyl->maximum)
		x_list_add(&ray->x_list, x_new(cyl, t[0]));
	y1 = l_ray->origin.y + t[1] * l_ray->direction.y;
	if (cyl->minimum < y1 && y1 < cyl->maximum)
		x_list_add(&ray->x_list, x_new(cyl, t[1]));
	if (cyl->capped && !float_cmp(l_ray->direction.y, 0.0, EPSILON))
		intersect_caps(ray, l_ray, cyl);
	return ;
}

static void	intersect_caps(t_ray *ray, t_ray *l_ray, t_object *cyl)
{
	double	t;
	double	x;
	double	z;

	t = (cyl->minimum - l_ray->origin.y) / l_ray->direction.y;
	x = l_ray->origin.x + t * l_ray->direction.x;
	z = l_ray->origin.z + t * l_ray->direction.z;
	if ((pow(x, 2) + pow(z, 2)) <= 1)
		x_list_add(&ray->x_list, x_new(cyl, t));
	return ;
}

t_tuple	normal_at_cylinder(t_object *cyl, t_tuple p)
{
	double	dist;

	dist = pow(p.x, 2) + pow(p.z, 2);
	if (dist < 1 && p.y >= cyl->maximum - EPSILON)
		return (vector(0, 1, 0));
	else if (dist < 1 && p.y <= cyl->minimum + EPSILON)
		return (vector(0, -1, 0));
	else
		return (vector(p.x, 0, p.z));
}
