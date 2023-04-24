/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/23 22:18:22 by cado-car         ###   ########.fr       */
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
	t_object	*s;

	data->camera = camera(IMG_X, IMG_Y, M_PI / 3);
	matrix_destroy(&data->camera.transform);
	data->camera.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), \
		vector(0, 1, 0));
	light_add(&(data->world.l_list), light_new(point(-10, 10, -10), \
		color(1, 1, 1, 1)));
	s = sphere_new(material(), translation(-0.5, 1, 0.5));
	s->material.color = color(0.1, 1, 0.5, 1);
	s->material.diffuse = 0.7;
	s->material.specular = 0.3;
	object_add(&(data->world.o_list), s);
	render(data);
}
