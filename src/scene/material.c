/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:05:50 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 12:44:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_material	material(t_color color, double amb, double dif, double spec)
{
	t_material	m;

	m.color = color;
	m.ambient = amb;
	m.diffuse = dif;
	m.specular = spec;
	m.shininess = 200.0;
	return (m);
}
