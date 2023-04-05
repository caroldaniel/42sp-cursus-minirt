/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_01.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 20:25:24 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/04 21:32:08 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../../inc/minirt.h"
#include "../../inc/tuples.h"
#include "../../lib/libft/libft.h"

/*
** Test for point creation
*/

int main(void)
{
	t_tuple *pnt;

	pnt = point(4, -4, 3);
	print_tuple(*pnt);
	free(pnt);
	return (0);
}
