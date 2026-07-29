/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:41:39 by scegla            #+#    #+#             */
/*   Updated: 2026/07/29 15:46:32 by scegla           ###   ########.fr       */
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

int	line_is_good(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '1')
			return (0);
		i++;
	}
	return (1);
}

int	str_is_white_space(char *c)
{
	int	i;

	i = 0;
	while (c[i] == ' ' || (c[i] >= 9 && c[i] <= 13))
		i++;
	if (!c[i])
		return (0);
	return (1);
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
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("The map need to be the last thing in the file", 2);
			r++;
		}
		free(str);
		str = get_next_line(fd);
	}
	free(str);
	return (r);
}

t_map	*make_map(int fd, t_map *new, t_map *maps)
{
	char	*str;
	int		resu;

	str = get_next_line(fd);
	while (line_is_good(str))
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str && str_is_white_space(str))
	{
		new = ft_lstnew_file(str);
		free(str);
		if (!new)
			return (NULL);
		ft_lstadd_back_map(&maps, new);
		if (!maps)
		{
			free_tmap(&new);
			return (NULL);
		}
		str = get_next_line(fd);
	}
	if (str)
	{
		resu = finish_gnl_of_the_map(fd);
		if (resu)
		{
			free(str);
			free_tmap(&maps);
			return (NULL);
		}
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
