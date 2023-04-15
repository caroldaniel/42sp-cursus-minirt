/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/14 23:46:38 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_on_grid(t_data *data);

void	image_create(t_data *data)
{
	image_init(data);
	draw_on_grid(data);
	image_generate(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

static void	draw_on_grid(t_data *data)
{
	t_light		light;
	t_tuple		p_obsv;
	
	t_object	s;
	t_matrix	t;

	t_ray		r;
	t_tuple		p_grid;
	t_hit		*h_light;
	
	int			x;
	int			y;

	light = point_light(point(-100, 100, -100), color(1, 1, 1, 1));
	s = sphere();
	t = scaling(42, 42, 42);
	set_transform(&s, t);
	p_obsv = point(0, 0, -50);

	y = -1 - (IMG_Y / 2);
	while (++y < IMG_Y / 2)
	{
		x = -1 - (IMG_X / 2);
		while (++x < IMG_X / 2)
		{
			p_grid = point(x, y, 10);
			r = ray(p_obsv, normalize(tuple_subtract(p_grid, p_obsv)));
			intersect_sphere(s, &r);
			h_light = get_hit_info(light, r);
			if (h_light)
			{
				put_pixel(data->img, x, y, lightning(*h_light));
				free(h_light);
			}
			ray_destroy(&r);
		}
	}
	object_destroy(&s);
}
