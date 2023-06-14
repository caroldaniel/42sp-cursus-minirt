/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 15:58:03 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/14 18:33:19 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCENE_H
# define SCENE_H

# include "minirt.h"

/*
** Camera type definition
*/
typedef struct s_cam
{
	int			hsize;
	int			vsize;
	double		field_of_view;
	t_matrix	transform;
	double		pixel_size;
	double		half_width;
	double		half_height;
}	t_cam;

/*
** Material type definition
*/
typedef struct s_material
{
	t_pattern	pattern;
	double		ambient;
	double		diffuse;
	double		specular;
	double		shininess;
}	t_material;

/*
** Light point type definition
*/
typedef struct s_light
{
	t_color			intensity;
	t_tuple			position;
	struct s_light	*next;
}	t_light;

/*
** Object type definition
*/
enum e_object {
	SPHERE,
	PLANE,
	CYLINDER,
	CONE
};

typedef struct s_object
{
	int				type;
	int				id;
	t_matrix		transform;
	t_material		material;
	double			minimum;
	double			maximum;
	bool			capped;
	struct s_object	*next;
}	t_object;

/*
** Intersection types definitions
*/
typedef struct s_x
{
	t_object	*object;
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
** Hit info type definition
*/
typedef struct s_hit
{
	t_tuple		point;
	t_tuple		eyev;
	t_tuple		normalv;
	t_light		light;
	t_material	material;
	t_color		color_hit;
	bool		inside;
	t_tuple		over_point;
	bool		in_shadow;
}	t_hit;

/*
** Hit info type definition
*/
typedef struct s_world
{
	t_light		*l_list;
	t_object	*o_list;
}	t_world;

/*
** Camera management
*/
t_matrix	view_transform(t_tuple from, t_tuple to, t_tuple up);
t_cam		camera(int hsize, int vsize, double field_of_view);
void		set_camera_transform(t_cam *cam, t_matrix transform);
void		camera_destroy(t_cam *cam);
t_ray		*ray_for_pixel(t_cam cam, int x, int y);

/*
** Point light list management
*/
t_light		*light_new(t_tuple position, t_color intensity);
void		light_add(t_light **pl, t_light *new);
void		light_destroy(t_light **pl);

/*
** Object list management
*/
t_object	*object_new(int type, int id);
void		object_add(t_object **ol, t_object *new);
void		object_list_destroy(t_object**ol);
void		set_object_transform(t_object *object, t_matrix t);
void		truncate_object(t_object *obj, t_ray *ray, t_ray *l_ray, double *t);
t_material	material(void);

/*
** Sphere
*/
t_object	*sphere_new(t_matrix transform);
void		intersect_sphere(t_object *s, t_ray *ray, t_ray *local_ray);
t_tuple		normal_at_sphere(t_object *s, t_tuple p);

/*
** Plane
*/
t_object	*plane_new(t_matrix transform);
void		intersect_plane(t_object *pl, t_ray *ray, t_ray *local_ray);
t_tuple		normal_at_plane(t_object *pl, t_tuple p);

/*
** Cylinder
*/
t_object	*cylinder_new(t_matrix transform, double min, double max, bool cap);
void		intersect_cylinder(t_object *cyl, t_ray *ray, t_ray *l_ray);
t_tuple		normal_at_cylinder(t_object *cyl, t_tuple p);

/*
** Cone
*/
t_object	*cone_new(t_matrix transform, double min, double max, bool cap);
void		intersect_cone(t_object *cone, t_ray *ray, t_ray *l_ray);
t_tuple		normal_at_cone(t_object *cone, t_tuple p);

/*
** Ray Operations
*/
t_ray		*ray_new(t_tuple origin, t_tuple direction);
void		ray_destroy(t_ray **ray);
t_tuple		position(t_ray *ray, double t);
t_ray		*transform(t_ray *ray, t_matrix m);
t_tuple		normal_at(t_object *o, t_tuple p);
t_tuple		reflect(t_tuple in, t_tuple nml);

/*
** Intersection list management
*/
t_x			*x_new(t_object *object, double t);
void		x_list_add(t_x **xl, t_x *new);
t_x			*x_list_copy(t_x *original);
void		x_list_destroy(t_x **xl);
void		print_x_list(t_ray ray);

/*
** Hit and point lighting
*/
t_x			*hit(t_ray *ray);
t_hit		*get_hit_info(t_world world, t_light *light, t_ray *ray);
void		hit_info_destroy(t_hit **h_light);
t_color		color_at(t_world world, t_ray *ray);
t_color		pattern_at_object(t_object *object, t_tuple world_point);

#endif