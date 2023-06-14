/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane_operations_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:50:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 14:37:55 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	intersect_plane(t_object *pl, t_ray *ray, t_ray *local_ray)
{
	double	t;

	if (comp(local_ray->direction.y, 0.0, EPSILON))
		return ;
	t = (-local_ray->origin.y) / local_ray->direction.y;
	x_list_add(&ray->x_list, x_new(pl, t));
	return ;
}

t_tuple	normal_at_plane(t_object *pl, t_tuple p)
{
	t_tuple		pl_nml;

	pl = (t_object *)pl;
	p = (t_tuple)p;
	pl_nml = vector(0, 1, 0);
	return (pl_nml);
}
