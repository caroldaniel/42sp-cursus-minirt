/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_create.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:59:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 14:04:13 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	draw_on_grid(t_data *data);

void	image_create(t_data *data)
{
	t_ray			r;
	int				s;
	t_x_list		xs;
	int				i;

	image_init(data);
	draw_on_grid(data);
	r = ray(point(0, 2, -5), vector(0, 0, 1));
	s = sphere();
	xs = intersect_sphere(s, r);
	printf("xs.count = %d\n", xs.count);
	i = -1;
	while (++i < xs.count)
	{
		printf("xs.t[%d] = %d\n", i, xs.list[i].object);
		printf("xs.t[%d] = %.2f\n\n", i, xs.list[i].t);
	}
	if (xs.count)
		free(xs.list);
	image_generate(&data->img);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img.ptr, 0, 0);
}

static void	draw_on_grid(t_data *data)
{
	t_tuple		hour;
	t_matrix	rot;
	t_color		c;
	int			i;

	hour = point(0, 200, 0);
	rot = rotation_z(M_PI / 6);
	c = color(1, 1, 1, 1);
	i = -1;
	while (++i < 12)
	{
		hour = matrix_tuple_multiply(rot, hour);
		put_pixel(data->img, hour.x, hour.y, c);
	}
	matrix_destroy(&rot);
}
