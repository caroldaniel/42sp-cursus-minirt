/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:45:34 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/16 17:47:21 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_tuple	perturb_normal(t_tuple normalv, t_tuple p, t_material m)
{
	t_tuple	perturbed;
	double	noise[3];
	m.bumpiness = fmax(0.0, fmin(1.0, m.bumpiness));
	if (comp(m.bumpiness, 0.0, EPSILON))
		return (normalv);
	p = tuple_divide(p, m.scale);
	noise[0] = perlin_noise(p.x, p.y, p.z, m) * m.bumpiness * 0.01;
	noise[1] = perlin_noise(p.y, p.z, p.z, m) * m.bumpiness * 0.01;
	noise[2] = perlin_noise(p.z, p.y, p.y, m) * m.bumpiness * 0.01;
	perturbed = vector(
		normalv.x + noise[0],
		normalv.y + noise[1],
		normalv.z + noise[2]
	);
	return (normalize(perturbed));
}
