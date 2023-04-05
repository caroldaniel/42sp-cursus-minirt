/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tuples.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 19:37:59 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/05 14:01:23 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TUPLES_H
# define TUPLES_H

typedef struct s_tuple
{
	double	x;
	double	y;
	double	z;
	double	w;
}	t_tuple;


/*
** Init
*/
t_tuple *tuple(double x, double y, double z, short w);
t_tuple *point(double x, double y, double z);
t_tuple *vector(double x, double y, double z);

/*
** Operations
*/
t_tuple	*tuple_add(t_tuple a, t_tuple b);
t_tuple	*tuple_subtract(t_tuple a, t_tuple b);
t_tuple	*tuple_negate(t_tuple a);
t_tuple *tuple_multiply(t_tuple a, double scalar);
t_tuple *tuple_divide(t_tuple a, double scalar);

double	magnitude(t_tuple v);
t_tuple *normalize(t_tuple v);
double	dot(t_tuple a, t_tuple b);
t_tuple *cross(t_tuple a, t_tuple b);

/*
** Utils
*/

void	print_tuple(t_tuple tuple);

#endif