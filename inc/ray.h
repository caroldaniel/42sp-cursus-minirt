/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:36:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 20:08:24 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stdarg.h>

# include "tuples.h"

typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

typedef struct s_x
{
	int			object;
	double		t;
	struct s_x	*next;
}	t_x;

typedef struct s_x_list
{
	int				count;
	t_x				*list;
}	t_x_list;

t_ray		ray(t_tuple origin, t_tuple direction);
t_x			*intersection(int object, double t);
t_x_list	x_list_init(void);
t_x_list	*x_list(t_x_list *xl, int count, ...);
void		x_list_add(t_x_list *xl, t_x *new);
t_x			*hit(t_x_list xl);

t_tuple		position(t_ray ray, double t);

int			sphere(void);
t_x_list	intersect_sphere(int sphere, t_ray ray);
void		print_x_list(t_x_list xl);

#endif