/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:55:56 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 22:36:06 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_object	sphere(void)
{
	static int	id = 0;
	t_object	sphere;

	id++;
	sphere.type = SPHERE;
	sphere.id = id;
	sphere.transform = identity(4);
	return (sphere);
}
