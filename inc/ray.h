/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 21:36:02 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/12 23:17:21 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include <stdarg.h>

# include "tuples.h"

/*
** Object types
*/
enum e_object {
	SPHERE
};

/*
** Object type definition
*/
typedef struct s_object
{
	int			type;
	int			id;
	t_matrix	transform;
}	t_object;

/*
** Ray type definition
*/
typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
}	t_ray;

/*
** INtersection and intersection list types definitions
*/
typedef struct s_x
{
	t_object	object;
	double		t;
	struct s_x	*next;
}	t_x;

typedef struct s_x_list
{
	int				count;
	t_x				*list;
}	t_x_list;

/*
** Ray Init
*/
t_ray		ray(t_tuple origin, t_tuple direction);

/*
** Objects Init
*/
t_object	sphere(void);

/*
** Ray Operations
*/
t_tuple		position(t_ray ray, double t);
t_ray		transform(t_ray r, t_matrix m);
t_x			*hit(t_x_list xl);

/*
** Intersection management
*/
t_x			*intersection(t_object object, double t);
t_x_list	x_list(t_x_list *xl, int count, ...);
t_x_list	x_list_init(void);
void		x_list_add(t_x_list *xl, t_x *new);
void		x_list_destroy(t_x_list *xl);

/*
** Objects operations
*/
t_x_list	intersect_sphere(t_object sphere, t_ray ray);
void		set_transform(t_object *object, t_matrix t);

/*
** Utils
*/
void		print_x_list(t_x_list xl);

#endif