/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:09:58 by cado-car          #+#    #+#             */
/*   Updated: 2023/05/15 21:56:34 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 1)
		exit(data_destroy(&data, ERR_WRNGARG));
	data_init(&data, argv[1]);
	image_create(&data);
	set_hooks(&data);
	mlx_loop(data.mlx_ptr);
	return (0);
}
