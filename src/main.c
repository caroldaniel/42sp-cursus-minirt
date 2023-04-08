/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:09:58 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/07 21:24:10 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_data	data;

	data_init(&data);
	image_create(&data);
	set_hooks(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
