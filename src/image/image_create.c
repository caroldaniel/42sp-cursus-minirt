/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/05/01 20:28:07 by cado-car         ###   ########.fr       */
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
	t_object	*left_wall;
	t_object	*right_wall;
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
	floor = sphere_new(material(), scaling(10, 0.01, 10));
	floor->material.color = color(1, 0.9, 0.9, 1);
	floor->material.specular = 0;
	left_wall = sphere_new(floor->material, chain_transform(4, \
		scaling(10, 0.01, 10), rotation_x(M_PI / 2), rotation_y(-M_PI / 4), \
		translation(0, 0, 5)));
	right_wall = sphere_new(floor->material, chain_transform(4, \
		scaling(10, 0.01, 10), rotation_x(M_PI / 2), rotation_y(M_PI / 4), \
		translation(0, 0, 5)));
	s1 = sphere_new(material(), translation(-0.5, 1, 0.5));
	s1->material.color = color(0.1, 1, 0.5, 1);
	s1->material.diffuse = 0.7;
	s1->material.specular = 0.3;
	s2 = sphere_new(material(), chain_transform(2, scaling(0.5, 0.5, 0.5), \
		translation(1.5, 0.5, -0.5)));
	s2->material.color = color(0.5, 1, 0.1, 1);
	s2->material.diffuse = 0.7;
	s2->material.specular = 0.3;
	s3 = sphere_new(material(), chain_transform(2, scaling(0.33, 0.33, 0.33), \
		translation(-1.5, 0.33, -0.75)));
	s3->material.color = color(1, 0.8, 0.1, 1);
	s3->material.diffuse = 0.7;
	s3->material.specular = 0.3;
	object_add(&(data->world.o_list), floor);
	object_add(&(data->world.o_list), left_wall);
	object_add(&(data->world.o_list), right_wall);
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
