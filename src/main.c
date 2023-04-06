/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 22:09:58 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/06 18:11:06 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(void)
{
	t_data	*data;

	data = data_init();
	if (!data)
		return (data_destroy(data, ERR_DATAINIT));
	set_hooks(data);
	mlx_loop(data->mlx);
	return (0);
}
