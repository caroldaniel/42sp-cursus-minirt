/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:32:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 22:32:42 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_sphere(t_object *s, t_ray *ray, t_ray *l_ray)
{
	t_bhaskara	_;

	_ = get_delta(s, l_ray);
	if (_.delta < 0)
		return ;
	x_list_add(&ray->x_list, x_new(s, (-_.b - sqrt(_.delta)) / (2 * _.a)));
	x_list_add(&ray->x_list, x_new(s, (-_.b + sqrt(_.delta)) / (2 * _.a)));
}

t_tuple	normal_at_sphere(t_object *s, t_tuple p)
{
	t_tuple	sph_nml;

	s = (t_object *)s;
	sph_nml = tuple_subtract(p, point(0, 0, 0));
	return (sph_nml);
}
