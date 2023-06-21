/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cone.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:49:04 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/20 17:38:03 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*cone_new(double min, double max)
{
	static int	id = 0;
	t_object	*cone;

	id++;
	cone = object_new(CONE, id);
	if (!cone)
		return (NULL);
	cone->minimum = min;
	cone->maximum = max;
	cone->capped = true;
	return (cone);
}
