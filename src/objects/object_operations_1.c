/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_operations_1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 14:49:57 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/14 15:49:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	set_transform(t_object *object, t_matrix t)
{
	matrix_destroy(&object->transform);
	object->transform = t;
}

t_tuple	normal_at(t_object o, t_tuple p)
{
	t_tuple	nml;

	if (o.type == SPHERE)
		nml = normal_at_sphere(o, p);
	else
		nml = tuple(0, 0, 0, 0);
	return (nml);
}

t_tuple	reflect(t_tuple in, t_tuple nml)
{
	t_tuple	mult;
	
	mult = tuple_multiply(nml, 2 * dot(in, nml));
	return (tuple_subtract(in, mult));
}
