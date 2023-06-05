/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/04 23:33:54 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	image_init(t_data *data);
static void	image_render(t_data *data);
static void	image_generate(t_data *data);

void	image_create(t_data *data)
{
	image_init(data);
	image_render(data);
	image_generate(data);
	image_display(data);
}

static void	image_init(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < data->img.y)
	{
		x = -1;
		while (++x < data->img.x)
			data->img.grid[y][x] = color(0, 0, 0, 1);
	}
}

static void	image_render(t_data *data)
{
	t_object	*floor;
	t_object	*s1;
	t_object	*s2;
	t_object	*s3;

	data->camera = camera(data->img.x, data->img.y, M_PI / 3);
	matrix_destroy(&data->camera.transform);
	data->camera.transform = view_transform(point(0, 1.5, -5), point(0, 1, 0), \
		vector(0, 1, 0));
	light_add(&(data->world.l_list), light_new(point(-10, 10, -10), \
		color(1, 1, 1, 1)));
	// light_add(&(data->world.l_list), light_new(point(10, 10, -10), 
	// 	color(1, 1, 1, 1)));
	floor = plane_new(material(), identity(4));
	floor->material.pattern = stripe_pattern(color(1, 0.5, 0.5, 1), color(1, 1, 1, 1), \
		scaling(0.2, 0.5, 0.2));
	floor->material.specular = 0;
	s1 = sphere_new(material(), translation(-0.5, 1, 0.5));
	s1->material.pattern = checker_pattern(color(1, 0.5, 0.5, 1), color(1, 1, 1, 1), \
		scaling(0.5, 0.2, 0.2));
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.3;
	s2 = sphere_new(material(), chain_transform(2, scaling(0.5, 0.5, 0.5), \
		translation(1.5, 0.5, -0.5)));
	s2->material.pattern = stripe_pattern(color(1, 0.5, 0.5, 1), color(1, 1, 1, 1), \
		chain_transform(2, scaling(0.2, 0.2, 0.2), translation(0.5, 0, 0)));
	s2->material.diffuse = 0.7;
	s2->material.specular = 0.3;
	s3 = cylinder_new(material(), identity(4));
	s3->material.pattern = checker_pattern(color(1, 0.5, 0.5, 1), color(1, 1, 1, 1), \
		scaling(0.2, 0.2, 0.2));
	s3->material.diffuse = 0.7;
	s3->material.specular = 0.3;
	object_add(&(data->world.o_list), floor);
	object_add(&(data->world.o_list), s1);
	object_add(&(data->world.o_list), s2);
	object_add(&(data->world.o_list), s3);
	render(data);
}

static void	image_generate(t_data *data)
{
	t_img	img;
	int		x;
	int		y;

	img = data->img;
	y = -1;
	while (++y < img.y)
	{
		x = -1;
		while (++x < img.x)
			img.data[y * img.x + x] = combine(img.grid[y][x], img);
	}
}
