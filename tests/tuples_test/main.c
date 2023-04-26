/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmoreira <fmoreira@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 21:53:15 by fmoreira          #+#    #+#             */
/*   Updated: 2023/04/26 23:02:05 by fmoreira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "tuplest.h"

t_proj	ft_tick(t_proj pro, t_envi env)
{
	t_proj aux;
	
	aux.p_posi = tuple_add(pro.p_posi, pro.v_velo);
	aux.v_velo = tuple_add(pro.v_velo, tuple_add(env.v_grav, env.v_wind));
	return (aux);
}

int	main()
{
	t_proj	pro;
	t_envi	env;

	pro.p_posi = tuple(0, 1, 0, 1);
	pro.v_velo = normalize(tuple(1, 1, 0, 0));
	env.v_grav = tuple(0, -0.1, 0, 0);
	env.v_wind = tuple(-0.01, 0, 0, 0);

	while (pro.p_posi.y >= 0.0)
	{
		pro = ft_tick(pro, env);
		printf("X:%.2f Y:%.2f Z:%.2f W:%.2f\n", pro.p_posi.x, pro.p_posi.y, pro.p_posi.z, pro.p_posi.w);
	}
}