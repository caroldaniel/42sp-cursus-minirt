/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:40:43 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 14:22:49 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	print_tuple(t_tuple tuple)
{
	if (tuple.w == 1.0)
		printf("\nTuple is a point\n\n");
	else
		printf("\nTuple is a vector\n\n");
	printf("tuple.x = %.1f\n", tuple.x);
	printf("tuple.y = %.1f\n", tuple.y);
	printf("tuple.z = %.1f\n", tuple.z);
	printf("tuple.w = %.1f\n", tuple.w);
	return ;
}
