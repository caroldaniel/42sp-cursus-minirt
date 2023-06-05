/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   world.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 11:39:05 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/05 16:09:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	world_init(t_data *data)
{
	data->world.l_list = NULL;
	data->world.o_list = NULL;
	
	return ;
}

void	world_destroy(t_world *world)
{
	light_destroy(&world->l_list);
	object_list_destroy(&world->o_list);
	return ;
}

void	intersect_world(t_world world, t_ray *ray)
{
	t_object	*curr;
	t_matrix	inv;
	t_ray		*local_ray;

	curr = world.o_list;
	while (curr)
	{
		inv = matrix_inverse(curr->transform);
		local_ray = transform(ray, inv);
		matrix_destroy(&inv);
		if (curr->type == SPHERE)
			intersect_sphere(curr, ray, local_ray);
		if (curr->type == PLANE)
			intersect_plane(curr, ray, local_ray);
		if (curr->type == CYLINDER)
			intersect_cylinder(curr, ray, local_ray);
		ray_destroy(&local_ray);
		curr = curr->next;
	}
	return ;
}
