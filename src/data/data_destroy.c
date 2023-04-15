/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_destroy.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/06 17:21:05 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/15 13:09:04 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static void	grid_destroy(t_img *img, int height);

int	data_destroy(t_data *data, int exit_code)
{
	if (!data->mlx_ptr)
		return (exit_code);
	grid_destroy(&data->img, IMG_Y);
	mlx_destroy_image(data->mlx_ptr, data->img.ptr);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	world_destroy(&data->world);
	return (exit_code);
}

static void	grid_destroy(t_img *img, int height)
{
	int	y;

	if (!img->grid)
		return ;
	y = -1;
	while (++y < height)
	{
		if (img->grid[y])
		{
			free(img->grid[y]);
			img->grid[y] = NULL;
		}
	}
	free(img->grid);
	img->grid = NULL;
}
