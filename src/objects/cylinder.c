/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:49:04 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 10:49:05 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*cylinder_new(t_matrix transform, double min, double max, bool cap)
{
	static int	id = 0;
	t_object	*cylinder;

	id++;
	cylinder = object_new(CYLINDER, id);
	if (!cylinder)
		return (NULL);
	set_object_transform(cylinder, transform);
	cylinder->minimum = min;
	cylinder->maximum = max;
	cylinder->capped = cap;
	return (cylinder);
}
