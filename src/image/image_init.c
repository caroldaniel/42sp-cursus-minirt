/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/07 20:47:01 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 21:26:54 by cado-car         ###   ########.fr       */
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
			data->img.grid[x][y] = color(1, 0.5, 0, 1);
			if (!data->img.grid[x][y])
				return ;
		}
	}
}
