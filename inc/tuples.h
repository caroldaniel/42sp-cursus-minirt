/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:37:59 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/04 21:37:55 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

typedef struct s_tuple
{
	float	x;
	float	y;
	float	z;
	float	w;
}	t_tuple;


/*
** Init
*/
t_tuple *tuple(float x, float y, float z, short w);
t_tuple *point(float x, float y, float z);
t_tuple *vector(float x, float y, float z);

/*
** Operations
*/
t_tuple	*tuple_add(t_tuple a, t_tuple b);
t_tuple	*tuple_subtract(t_tuple a, t_tuple b);
t_tuple	*tuple_negate(t_tuple a);

/*
** Utils
*/

void	print_tuple(t_tuple tuple);

#endif