/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 21:50:35 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/20 17:36:56 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*plane_new(void)
{
	static int	id = 0;
	t_object	*plane;

	id++;
	plane = object_new(PLANE, id);
	if (!plane)
		return (NULL);
	return (plane);
}
