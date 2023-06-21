/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/20 21:15:32 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/20 21:47:46 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

/*------LIBRARIES------*/

# include <stdlib.h>
# include "minirt.h"

/*
** Parser elements struct definition
*/
typedef struct s_line
{
	char			**tokens;
	struct s_line	*next;
}	t_line;

/*
**	ELements struct definition
*/
typedef struct s_element
{
	int		count;
	bool	locked;
}	t_element;

/*
** Elements counter struct definition
*/
typedef struct s_counter
{
	t_element	ambient;
	t_element	camera;
	t_element	light;
	t_element	sphere;
	t_element	plane;
	t_element	cylinder;
	t_element	cone;
}	t_counter;

/*
**	Parser line struct utils
*/
t_line		*line_new(char *content);
void		line_add(t_line **list, t_line *new);
void		line_destroy(t_line **line);
void		line_list_destroy(t_line *list);

/*
**	Parser utils
*/
void		parser(t_data *data);
char		**tokenizer(char const *s);
void		token_array_destroy(char **matrix);

/*
**	Checkers
*/
bool		check_count(t_line *line);
bool		check_element(char *identifier);
bool		check_element_properties_count(t_line *line);
bool		check_range(double value, double min, double max);
bool		check_ratio(char *token);
bool		check_int(char *token);
bool		check_double(char *token);
bool		check_color(char *token);
bool		check_tuple(char *token);
bool		check_normalized_vector(char *token);
bool		check_material(char **tokens);

/*
**	Getters
*/
t_color		get_color(char *token);
t_tuple 	get_vector(char *token);
t_tuple 	get_point(char *token);
t_pattern	get_pattern(char *pattern, char *color_str);
bool		get_element_properties(t_line *line);
t_light		*get_ambient(t_line *line, t_data *data);
t_light 	*get_light(t_line *line, t_data *data);
t_cam		*get_camera(t_line *line, t_data *data);
t_object	*get_sphere(t_line *line, t_data *data);

#endif