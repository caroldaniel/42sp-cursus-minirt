/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 21:38:10 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/21 11:19:48 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_line	*line_new(char *content)
{
	t_line	*line;

	line = (t_line *)malloc(sizeof(t_line));
	if (!line)
		return (NULL);
	line->tokens = tokenizer(content);
	line->next = NULL;
	return (line);
}

void	line_add(t_line **list, t_line *new)
{
	t_line	*curr;

	if (!list || !new)
		return ;
	curr = *list;
	if (!curr)
	{
		*list = new;
		return ;
	}
	while (curr->next)
		curr = curr->next;
	curr->next = new;
	return ;
}

void	line_destroy(t_line **line)
{
	if (*line)
	{
		if ((*line)->tokens)
			token_array_destroy((*line)->tokens);
		free(*line);
		*line = NULL;
	}
	return ;
}

void	line_list_destroy(t_line **list)
{
	t_line	*curr;
	t_line	*next;

	curr = *list;
	while (curr)
	{
		next = curr->next;
		line_destroy(&curr);
		curr = next;
	}
	*list = NULL;
	return ;
}
