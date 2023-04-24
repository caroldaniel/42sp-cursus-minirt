/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:55:56 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/23 11:54:41 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*sphere_new(t_material material, t_matrix transform)
{
	static int	id = 0;
	t_object	*sphere;

	id++;
	sphere = object_new(SPHERE, id, material);
	if (!sphere)
		return (NULL);
	set_transform(sphere, transform);
	return (sphere);
}
