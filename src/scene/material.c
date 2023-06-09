/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:05:50 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 15:04:26 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	material(void)
{
	t_material	m;

	m.pattern = solid_pattern(color(1, 1, 1, 1));
	m.perlin = perlin_init();
	m.diffuse = 0.9;
	m.specular = 0.9;
	m.shininess = 200.0;
	m.bumpiness = 0.0;
	m.scale = 0.01;
	return (m);
}
