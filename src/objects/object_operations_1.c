/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:49:57 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 00:35:30 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_object *object, t_matrix t)
{
	matrix_destroy(&object->transform);
	object->transform = t;
}

t_tuple	normal_at(t_object *o, t_tuple p)
{
	t_tuple	nml;


	if (o->type == SPHERE)
		nml = normal_at_sphere(o, p);
	else if (o->type == PLANE)
		nml = normal_at_plane(o);
	else
		nml = tuple(0, 0, 0, 0);
	return (nml);
}
