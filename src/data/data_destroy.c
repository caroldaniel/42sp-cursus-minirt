/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:21:05 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 21:23:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	grid_destroy(t_img *img, int width, int height);

int	data_destroy(t_data *data, int exit_code)
{
	if (!data->mlx_ptr)
		return (exit_code);
	if (data->img.grid)
		grid_destroy(&data->img, IMG_X, IMG_Y);
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	return (exit_code);
}

static void	grid_destroy(t_img *img, int width, int height)
{
	int	x;
	int	y;

	x = -1;
	while (++x < width)
	{
		if (!img->grid[x])
			break ;
		y = -1;
		while (++y < height)
		{
			if (!img->grid[x][y])
				break ;
			free(img->grid[x][y]);
		}
		free(img->grid[x]);
	}
	free(img->grid);
}
