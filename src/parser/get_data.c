/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:44:26 by scegla            #+#    #+#             */
/*   Updated: 2026/07/23 15:32:32 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	identifier_good(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int	error_in_info(char *str, int fd, int i)
{
	free(str);
	finish_gnl(fd);
	if (i)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Wrong identifier in map.", 2);
	}
	return (1);
}

int	send_info(const t_set_id *list, int fd, char *str, t_game **game)
{
	int				j;
	int				i;

	i = 0;
	j = 0;
	while (str[j] == ' ')
		j++;
	while (list[i].type)
	{
		if (!ft_strncmp(&str[j], list[i].type, ft_strlen(list[i].type)))
		{
			if (list[i].f(game, &str[until_space(str)]))
				return (error_in_info(str, fd, 0));
			break ;
		}
		i++;
	}
	if (!list[i].type)
		return (error_in_info(str, fd, 1));
	return (0);
}

int	get_textures(char *str, int fd, t_game **game)
{
	int				nb;
	const t_set_id	list[] = {{"NO", no}, {"SO", so}, {"WE", we},
	{"EA", ea}, {"F", f}, {"C", c}, {NULL, NULL}};

	nb = 0;
	while (nb != 6)
	{
		while (identifier_good(str))
		{
			free(str);
			str = get_next_line(fd);
		}
		if (send_info(list, fd, str, game))
			return (1);
		free(str);
		str = get_next_line(fd);
		nb++;
	}
	free(str);
	return (0);
}

int	map_valid(t_game **game, int fd)
{
	char			*str;
	int				nb;

	nb = 0;
	str = get_next_line(fd);
	if (!str)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("The file is empty.", 2);
		return (1);
	}
	if (get_textures(str, fd, game))
		return (1);
	(*game)->map = get_map(fd);
	if (!(*game)->map)
	{
		finish_gnl(fd);
		return (1);
	}
	return (0);
}
