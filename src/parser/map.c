/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:41:39 by scegla            #+#    #+#             */
/*   Updated: 2026/08/01 11:30:29 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**create_map(t_map *maps)
{
	t_map	*tmp;
	char	**real_map;
	int		i;

	i = 0;
	real_map = ft_calloc(sizeof(char *), ft_tmapsize(maps) + 1);
	if (!real_map)
		return (NULL);
	tmp = maps;
	while (tmp)
	{
		real_map[i] = ft_strdup(tmp->map);
		if (!real_map[i])
		{
			free_memory(real_map);
			return (NULL);
		}
		tmp = tmp->next;
		i++;
	}
	return (real_map);
}

int	finish_gnl_of_the_map(int fd)
{
	char	*str;
	int		r;

	r = 0;
	str = get_next_line(fd);
	while (str)
	{
		if (r == 0 && str_is_white_space(str))
		{
			error_handler("The map need to be the last thing in the file");
			r++;
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (r);
}

char	*stock_map(int fd, t_map *new, t_map **maps, char *str)
{
	while (str && str_is_white_space(str))
	{
		new = ft_lstnew_file(str);
		free(str);
		if (!new)
			return (NULL);
		ft_lstadd_back_map(maps, new);
		if (!*maps)
		{
			free_tmap(&new);
			return (NULL);
		}
		str = get_next_line(fd);
	}
	return (str);
}

t_map	*make_map(int fd, t_map *new, t_map *maps)
{
	char	*str;
	int		resu;

	str = get_next_line(fd);
	while (line_is_good(str))
	{
		if (!str)
		{
			error_handler("There is no map");
			return (NULL);
		}
		free(str);
		str = get_next_line(fd);
	}
	str = stock_map(fd, new, &maps, str);
	if (str)
	{
		resu = finish_gnl_of_the_map(fd);
		free(str);
		if (resu)
			free_tmap(&maps);
	}
	return (maps);
}

char	**get_map(int fd)
{
	t_map	*maps;
	t_map	*new;
	t_map	*pre;
	char	**real_map;

	maps = NULL;
	new = NULL;
	pre = NULL;
	maps = make_map(fd, new, maps);
	if (!maps)
		return (NULL);
	real_map = create_map(maps);
	free_tmap(&maps);
	if (!real_map)
		return (NULL);
	return (real_map);
}
