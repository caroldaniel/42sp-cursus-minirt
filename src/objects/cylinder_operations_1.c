/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder_operations_1.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:50:49 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/05 00:15:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	add_trucate_x(t_ray *ray, t_object *c, double t0, double t1);

void	intersect_cylinder(t_object *c, t_ray *ray)
{
	t_ray		*ray_t;
	double		coef[3];
	double		disc;
	double		t[2];

	ray_t = transform(ray, matrix_inverse(c->transform));
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
		add_trucate_x(ray, c, t[1], t[0]);
	else
		add_trucate_x(ray, c, t[0], t[1]);
	return ;
}
static void	add_trucate_x(t_ray *ray, t_object *c, double t0, double t1)
{
	double	y0;
	double	y1;

	y0 = ray->origin.y + t0 * ray->direction.y;
	if (c->minimum < y0 && y0 < c->maximum)
		x_list_add(&ray->x_list, x_new(c, t0));
	y1 = ray->origin.y + t1 * ray->direction.y;
	if (c->minimum < y1 && y1 < c->maximum)
		x_list_add(&ray->x_list, x_new(c, t1));
	return ;
}

t_tuple	normal_at_cylinder(t_object *c, t_tuple p)
{
	t_matrix	inv;
	t_matrix	trs;
	t_tuple		o_p;
	t_tuple		o_nml;
	t_tuple		nml;

	inv = matrix_inverse(c->transform);
	o_p = matrix_tuple_multiply(inv, p);
	o_nml = vector(o_p.x, 0, o_p.z);
	trs = matrix_transpose(inv);
	nml = matrix_tuple_multiply(trs, o_nml);
	nml.w = 0;
	matrix_destroy(&inv);
	matrix_destroy(&trs);
	return (normalize(nml));
}
