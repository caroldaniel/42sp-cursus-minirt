/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:49:04 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 16:40:22 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*cone_new(t_matrix transform, double min, double max, bool cap)
{
	static int	id = 0;
	t_object	*cone;

	id++;
	cone = object_new(CONE, id);
	if (!cone)
		return (NULL);
	set_object_transform(cone, transform);
	cone->minimum = min;
	cone->maximum = max;
	cone->capped = cap;
	return (cone);
}
