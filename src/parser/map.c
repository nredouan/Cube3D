/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:41:39 by scegla            #+#    #+#             */
/*   Updated: 2026/07/15 14:04:53 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

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

t_map	*make_map(int fd, t_map *new, t_map *maps)
{
	char	*str;

	str = get_next_line(fd);
	while (line_is_good(str))
	{
		free(str);
		str = get_next_line(fd);
	}
	while (str)
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
	return (maps);
}

char	**get_map(int fd)
{
	t_map	*maps;
	t_map	*new;
	char	**real_map;

	maps = NULL;
	new = NULL;
	maps = make_map(fd, new, maps);
	real_map = create_map(maps);
	free_tmap(&maps);
	if (!real_map)
		return (NULL);
	return (real_map);
}
