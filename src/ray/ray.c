/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:35:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 12:07:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	*ray_new(t_tuple origin, t_tuple direction)
{
	t_ray	*ray;

	ray = malloc(sizeof(t_ray));
	if (!ray)
		return (NULL);
	ray->origin = origin;
	ray->direction = direction;
	ray->x_list = NULL;
	return (ray);
}

void	ray_destroy(t_ray **ray)
{
	if (!(*ray))
		return ;
	if ((*ray)->x_list)
		x_list_destroy(&(*ray)->x_list);
	free(*ray);
	return ;
}
