/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_operations_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:50:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/05 12:31:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_cylinder_x(t_ray *ray, t_object *c, double t0, double t1);
static void intersect_caps(t_ray *ray, t_object *cyl);

void	intersect_cylinder(t_object *cyl, t_ray *ray)
{
	t_ray		*ray_t;
	double		coef[3];
	double		disc;
	double		t[2];

	ray_t = transform(ray, matrix_inverse(cyl->transform));
	coef[0] = pow(ray_t->direction.x, 2.0) + pow(ray_t->direction.z, 2.0);
	if (float_cmp(coef[0], 0.0, 0.001) == true)
		return ;
	coef[1] = 2 * ray_t->origin.x * ray_t->direction.x + \
		2 * ray_t->origin.z * ray_t->direction.z;
	coef[2] = pow(ray_t->origin.x, 2.0) + pow(ray_t->origin.z, 2.0) - 1;
	ray_destroy(&ray_t);
	disc = pow(coef[1], 2.0) - 4.0 * coef[0] * coef[2];
	if (disc < 0)
		return ;
	t[0] = (-coef[1] - sqrt(disc)) / (2 * coef[0]);
	t[1] = (-coef[1] + sqrt(disc)) / (2 * coef[0]);
	if (t[0] > t[1])
		add_cylinder_x(ray, cyl, t[1], t[0]);
	else
		add_cylinder_x(ray, cyl, t[0], t[1]);
	return ;
}
static void	add_cylinder_x(t_ray *ray, t_object *cyl, double t0, double t1)
{
	double	y0;
	double	y1;

	y0 = ray->origin.y + t0 * ray->direction.y;
	if (cyl->minimum < y0 && y0 < cyl->maximum)
		x_list_add(&ray->x_list, x_new(cyl, t0));
	y1 = ray->origin.y + t1 * ray->direction.y;
	if (cyl->minimum < y1 && y1 < cyl->maximum)
		x_list_add(&ray->x_list, x_new(cyl, t1));
	if (cyl->capped && !float_cmp(ray->direction.y, 0.0, 0.001))
		intersect_caps(ray, cyl);
	return ;
}

static void intersect_caps(t_ray *ray, t_object *cyl)
{
	double	t;
	double	x;
	double	z;
	
	t = (cyl->minimum - ray->origin.y) / ray->direction.y;
	x = ray->origin.x + t * ray->direction.x;
	z = ray->origin.z + t * ray->direction.z;
	if ((pow(x, 2) + pow(z, 2)) <= 1)
		x_list_add(&ray->x_list, x_new(cyl, t));
	return ;
}

t_tuple	normal_at_cylinder(t_object *cyl, t_tuple p)
{
	double	dist;
	t_tuple	cyl_nml;

	dist = pow(p.x, 2) + pow(p.z, 2);
	if (dist < 1 && p.y >= cyl->maximum - 0.001)
		cyl_nml = vector(0, 1, 0);
	else if (dist < 1 && p.y <= cyl->maximum + 0.001)
		cyl_nml = vector(0, -1, 0);
	else
		cyl_nml = vector(p.x, 0, p.z);
	return (cyl_nml);
}
