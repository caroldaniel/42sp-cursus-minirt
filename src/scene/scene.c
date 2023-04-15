/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 17:48:41 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/14 22:56:08 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_light	point_light(t_tuple position, t_color intensity)
{
	t_light	p_light;

	p_light.position = position;
	p_light.intensity = intensity;
	return (p_light);
}
