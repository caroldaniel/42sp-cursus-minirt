/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/04 22:49:04 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 22:50:06 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minirt.h"

t_object	*cylinder_new(t_material material, t_matrix transform)
{
	static int	id = 0;
	t_object	*cylinder;

	id++;
	cylinder = object_new(CYLINDER, id, material);
	if (!cylinder)
		return (NULL);
	set_transform(cylinder, transform);
	return (cylinder);
}
