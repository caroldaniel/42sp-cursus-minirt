/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/20 23:48:34 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	image_pointer_init(t_data *data);
static void	image_render(t_data *data);
static void	image_generate(t_data *data);

void	image_create(t_data *data)
{
	image_pointer_init(data);
	image_render(data);
	image_generate(data);
	image_display(data);
}

static void	image_pointer_init(t_data *data)
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
	t_ray	*ray;
	t_color	c;
	int		y;
	int		x;

	y = -1;
	while (++y < data->camera->vsize)
	{
		x = -1;
		while (++x < data->camera->hsize)
		{
			ray = ray_for_pixel(data->camera, x, y);
			c = color_at(data->world, ray);
			put_pixel(data->img, x, y, c);
			ray_destroy(&ray);
			update_progress_bar((x + (y * data->camera->hsize)), \
				data->camera->vsize * data->camera->hsize);
		}
	}
	update_progress_bar((x + (y * data->camera->hsize)), \
		data->camera->vsize * data->camera->hsize);
	printf("\n%sRendering Complete%s\n", ESC_BOLD_GREEN, ESC_RESET_COLOR);
	return ;
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
