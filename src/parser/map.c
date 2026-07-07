/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 12:41:39 by scegla            #+#    #+#             */
/*   Updated: 2026/07/07 15:53:04 by scegla           ###   ########.fr       */
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

char	**get_map(int fd)
{
	char	*str;
	t_map	*maps;
	t_map	*new;
	char	**real_map;

	maps = NULL;
	new = NULL;
	str = get_next_line(fd);
	if (!strncmp(str, "\n", 1))
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
	real_map = create_map(maps);
	free_tmap(&maps);
	if (!real_map)
		return (NULL);
	return (real_map);
}
