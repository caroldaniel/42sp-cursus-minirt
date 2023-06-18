/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cado-car <cado-car@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/17 20:47:00 by cado-car          #+#    #+#             */
/*   Updated: 2023/06/17 22:46:09 by cado-car         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static size_t	token_count(const char *s);
static void		create_token(char **result, char const *s);
static size_t	add_token(char **result, const char *prev, size_t size);
static bool		is_separator(char c);

char	**tokenizer(char const *s)
{
	char	**result;

	if (!s)
		return (NULL);
	result = (char **)malloc((token_count(s) + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	create_token(result, s);
	return (result);
}

static size_t	token_count(const char *s)
{
	size_t	i;
	size_t	prev;
	size_t	next;
	size_t	size;
	size_t	counter;

	i = 0;
	prev = i;
	next = i;
	counter = 0;
	while (1)
	{
		if (is_separator(s[i]) || s[i] == '\0')
			next = i;
		size = next - prev;
		if (size > 1 || (size == 1 && !is_separator(s[i - 1])))
			counter++;
		if (s[i] == '\0')
			break ;
		prev = next;
		i++;
	}
	return (counter);
}

static void	create_token(char **result, char const *s)
{
	size_t	i;
	size_t	j;
	size_t	size;
	size_t	prev;
	size_t	next;

	i = 0;
	j = 0;
	prev = i;
	next = i;
	while (1)
	{
		if (is_separator(s[i]) || s[i] == '\0')
			next = i;
		size = next - prev;
		if (size > 1 || (size == 1 && !is_separator(s[i - 1])))
			j += add_token(&result[j], &s[prev], size);
		if (s[i] == '\0')
			break ;
		prev = next;
		i++;
	}
	result[j] = NULL;
}

static size_t	add_token(char **result, const char *prev, size_t size)
{
	if (is_separator(*prev))
	{
		prev++;
		size--;
	}
	*result = (char *)malloc((size + 1) * sizeof(char));
	if (*result == NULL)
		return (0);
	ft_strlcpy(*result, prev, size + 1);
	return (1);
}

static bool	is_separator(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (true);
	return (false);
}
