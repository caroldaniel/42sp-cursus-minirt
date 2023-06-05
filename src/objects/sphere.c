/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:55:56 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 23:56:15 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*sphere_new(t_matrix transform)
{
	static int	id = 0;
	t_object	*sphere;

	id++;
	sphere = object_new(SPHERE, id);
	if (!sphere)
		return (NULL);
	set_transform(sphere, transform);
	return (sphere);
}
