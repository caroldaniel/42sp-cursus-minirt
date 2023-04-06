/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:09:58 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 16:34:50 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_data	*data;

	data = data_init();
	if (!data)
		return (1);	
	data->mlx_win = mlx_new_window(data->mlx, 1920, 1000, MINIRT);
	mlx_loop(data->mlx);
	return (0);
}
