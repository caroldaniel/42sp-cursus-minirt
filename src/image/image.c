/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:47:01 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 23:57:28 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	image_init(t_data *data)
{
	int	x;
	int	y;

	x = -1;
	while (++x < IMG_X)
	{
		y = -1;
		while (++y < IMG_Y)
		{
			data->img.grid[x][y] = color(0, 0, 0, 1);
			if (!data->img.grid[x][y])
				return ;
		}
	}
}

void	put_pixel(t_img img, int x, int y, t_color *color)
{
	if (x < 0 || y < 0)
		return ;
	if (x > IMG_X || y > IMG_Y)
		return ;
	free(img.grid[x][y]);
	img.grid[x][y] = color;
}
