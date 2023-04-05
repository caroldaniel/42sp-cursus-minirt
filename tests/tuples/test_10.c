/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_10.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:25:24 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 15:15:31 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minirt.h"
#include "../../inc/tuples.h"
#include "../../lib/libft/libft.h"

/*
** Test for tuples negation
*/

int main(void)
{
	t_tuple *vct;
	t_tuple *neg;

	printf("\nThis is a tuple:\n");
	vct = vector(4, -4, 3);
	print_tuple(*vct);
	printf("\nNow, let's negate it:\n");
	neg = tuple_negate(*vct);
	if (!neg)
		printf("Can't negate a point!\n");
	else
	{
		print_tuple(*neg);
		free(neg);
	}
	free(vct);
	return (0);
}
