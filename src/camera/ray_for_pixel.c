/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_for_pixel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 15:07:05 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/24 11:51:01 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_ray	*ray_for_pixel(t_cam cam, int x, int y)
{
	double		offset[2];
	double		world[2];
	t_matrix	inv_c;
	t_tuple		pixel;
	t_tuple		origin;

	offset[0] = (x + 0.5) * cam.pixel_size;
	offset[1] = (y + 0.5) * cam.pixel_size;
	world[0] = cam.half_width - offset[0];
	world[1] = cam.half_height - offset[1];
	inv_c = matrix_inverse(cam.transform);
	pixel = matrix_tuple_multiply(inv_c, point(world[0], world[1], -1.0));
	origin = matrix_tuple_multiply(inv_c, point(0.0, 0.0, 0.0));
	matrix_destroy(&inv_c);
	return (ray_new(origin, normalize(tuple_subtract(pixel, origin))));
}
