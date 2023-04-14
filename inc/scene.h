/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:58:03 by cado-car          #+#    #+#             */
/*   Updated: 2023/04/14 19:54:45 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

#include "minirt.h"

typedef struct s_material
{
	t_color	color;
	double	ambient;
	double	diffuse;
	double	specular;
	double	shininess;
}	t_material;

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
	t_material	material;
}	t_object;

/*
** INtersection and intersection list types definitions
*/
typedef struct s_x
{
	t_object	object;
	double		t;
	struct s_x	*next;
}	t_x;

/*
** Ray type definition
*/
typedef struct s_ray
{
	t_tuple	origin;
	t_tuple	direction;
	t_x		*x_list;
}	t_ray;

/*
** Ray Init
*/
t_ray	ray(t_tuple origin, t_tuple direction);
void	ray_destroy(t_ray *ray);

/*
** Objects Init
*/
t_object	sphere(void);

/*
** Ray Operations
*/
t_tuple	position(t_ray ray, double t);
t_ray	transform(t_ray ray, t_matrix m);
t_x		*hit(t_ray ray);

/*
** Intersection list management
*/
t_x		*x_new(t_object object, double t);
void	x_list_add(t_x **xl, t_x *new);
t_x		*x_list_copy(t_x *original);
void	x_list_destroy(t_x **xl);

/*
** Objects operations
*/
void	object_destroy(t_object *o);
void	set_transform(t_object *object, t_matrix t);
t_tuple	normal_at(t_object o, t_tuple p);
t_tuple	reflect(t_tuple in, t_tuple nml);

/*
** Sphere
*/
void	intersect_sphere(t_object s, t_ray *ray);
t_tuple	normal_at_sphere(t_object s, t_tuple p);

/*
** Utils
*/
void	print_x_list(t_ray *ray);

typedef struct s_light
{
	t_color intensity;
	t_tuple position;
}	t_light;

typedef struct s_scene
{
	t_light	light;
	t_tuple	eyev;
}	t_scene;

typedef struct s_lighting
{
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_light		light;
	t_material	material;
}	t_lighting;

t_lighting	point_on_light(t_scene s, t_ray ray, t_x *hit);

t_color		lightning(t_lighting p);

t_scene		scene(t_light light, t_tuple camera);
t_light		point_light(t_tuple position, t_color intensity);
t_material	material(void);

#endif