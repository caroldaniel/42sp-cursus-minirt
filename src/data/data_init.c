/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 16:21:21 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/06 23:45:40 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	data_init(t_data *data)
{
	data->mlx = mlx_init();
	if (!data->mlx)
		exit(data_destroy(data, ERR_MLXINIT));
	data->mlx_win = mlx_new_window(data->mlx, 400, 300, MINIRT);
}
