/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 13:08:10 by cado-car         ###   ########.fr       */
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
	// t_tuple		p_obsv;
	// t_tuple		p_grid;
	t_ray		*ray;
	// t_hit		*h_light;
	
	// int			x;
	// int			y;

	light_add(&data->world.l_list, light_new(point(-100, 100, -100), \
		color(1, 1, 1, 1)));
	object_add(&data->world.o_list, sphere_new(material(color(0.8, 1, 0.6, 1), \
		0.1, 0.7, 0.2), identity(4)));
	object_add(&data->world.o_list, sphere_new(material(color(1, 0.02, 1, 1), \
		0.1, 0.9, 0.9), scaling(0.5, 0.5, 0.5)));
	ray = ray_new(point(0, 0, -5), vector (0, 0, 1));
	intersect_world(data->world, ray);
	print_x_list(*ray);
	ray_destroy(&ray);
	// p_obsv = point(0, 0, -50);
	// y = -1 - (IMG_Y / 2);
	// while (++y < IMG_Y / 2)
	// {
	// 	x = -1 - (IMG_X / 2);
	// 	while (++x < IMG_X / 2)
	// 	{
	// 		p_grid = point(x, y, 10);
	// 		ray = ray_new(p_obsv, normalize(tuple_subtract(p_grid, p_obsv)));
	// 		intersect_sphere(s1, ray);
	// 		h_light = get_hit_info(light, ray);
	// 		if (h_light)
	// 		{
	// 			put_pixel(data->img, x, y, lightning(*h_light));
	// 			hit_info_destroy(&h_light);
	// 		}
	// 		ray_destroy(&ray);
	// 	}
	// }
}
