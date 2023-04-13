/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/13 00:31:36 by cado-car         ###   ########.fr       */
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
	t_x_list	xl;
	t_object	s;
	t_matrix	t;
	int			x;
	int			y;

	s = sphere();
	t = scaling(3, 3, 3);
	set_transform(&s, t);
	y = -1 - (IMG_Y / 2);
	while (++y < IMG_Y / 2)
	{
		x = -1 - (IMG_X / 2);
		while (++x < IMG_X / 2)
		{
			xl = intersect_sphere(s, ray(point(0, 0, -4), \
				normalize(tuple_subtract(point(x, y, 10), point(0, 0, -4)))));
			if (hit(xl))
				put_pixel(data->img, x, y, color(1, 0, 0, 1));
			x_list_destroy(&xl);
		}
	}
	matrix_destroy(&t);
}
