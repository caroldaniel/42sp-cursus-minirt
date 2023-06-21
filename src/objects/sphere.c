/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:55:56 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/20 17:36:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*sphere_new(void)
{
	static int	id = 0;
	t_object	*sphere;

	id++;
	sphere = object_new(SPHERE, id);
	if (!sphere)
		return (NULL);
	return (sphere);
}
