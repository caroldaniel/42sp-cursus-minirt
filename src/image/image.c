/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:47:01 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/10 21:14:17 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	image_init(t_data *data)
{
	int	x;
	int	y;

	y = -1;
	while (++y < IMG_Y)
	{
		x = -1;
		while (++x < IMG_X)
			data->img.grid[y][x] = color(0, 0, 0, 1);
	}
}

void	put_pixel(t_img img, int x, int y, t_color color)
{
	if (x < -IMG_X / 2 || y < -IMG_Y / 2)
		return ;
	if (x > IMG_X / 2 || y > IMG_Y / 2)
		return ;
	img.grid[y + IMG_Y / 2][x + IMG_X / 2] = color;
}
