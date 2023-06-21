/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:49:04 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/20 17:37:44 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	*cylinder_new(double min, double max)
{
	static int	id = 0;
	t_object	*cylinder;

	id++;
	cylinder = object_new(CYLINDER, id);
	if (!cylinder)
		return (NULL);
	cylinder->minimum = min;
	cylinder->maximum = max;
	cylinder->capped = true;
	return (cylinder);
}
