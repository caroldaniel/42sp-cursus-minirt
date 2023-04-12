/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:36:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 14:06:00 by cado-car         ###   ########.fr       */
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

typedef struct s_intersection
{
	int		object;
	double	t;
}	t_intersection;

typedef struct s_x_list
{
	int				count;
	t_intersection	*list;
}	t_x_list;

t_ray			ray(t_tuple origin, t_tuple direction);
t_intersection	intersection(int object, double t);
t_x_list		x_list(int count, ...);

t_tuple			position(t_ray ray, double t);

int				sphere(void);
t_x_list		intersect_sphere(int sphere, t_ray ray);

#endif