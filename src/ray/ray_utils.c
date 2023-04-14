/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:01:26 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/14 16:36:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_x_list(t_ray *ray)
{
	t_x	*curr;

	curr = ray->x_list;
	if (!curr)
		printf("No intersections!\n");
	while (curr)
	{
		printf("t = %f\n", curr->t);
		curr = curr->next;
	}
}
