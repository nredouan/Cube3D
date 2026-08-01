/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fandc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:57:00 by scegla            #+#    #+#             */
/*   Updated: 2026/08/01 11:39:25 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**good_rgb(char *info)
{
	int		i;
	int		j;
	char	**rgb;

	i = 0;
	rgb = ft_split(info, ',');
	while (rgb[i])
	{
		j = 0;
		while (rgb[i][j])
		{
			if (rgb[i][j] != '\n' && rgb[i][j] != ' ' && !ft_isdigit(rgb[i][j]))
				return (not_digit(rgb));
			j++;
		}
		i++;
	}
	if (i != 3)
	{
		error_handler("RGB format is not valid.");
		free_memory(rgb);
		return (NULL);
	}
	return (rgb);
}

int	arg_not_valid(char *str)
{
	error_handler(str);
	return (1);
}

int	arg_exist(char *info, int f)
{
	int	i;
	int	comma;

	i = 0;
	comma = 0;
	if (f != -1)
		return (arg_not_valid("Invalid data."));
	if (!info)
		return (arg_not_valid("Missing information."));
	while (info[i])
	{
		if (info[i] == ',')
			comma++;
		i++;
	}
	if (comma > 2)
		return (arg_not_valid("RGB format is not valid."));
	return (0);
}

int	f(t_game **game, char *info)
{
	char	**rgb;
	int		i;
	int		nb;

	if (arg_exist(info, (*game)->f[0]))
		return (1);
	rgb = good_rgb(info);
	if (!rgb)
		return (1);
	i = 0;
	while (rgb[i])
	{
		nb = ft_atoi(rgb[i]);
		if (nb >= 0 && nb <= 255)
			(*game)->f[i] = nb;
		else
		{
			error_handler("RGB format is not valid.");
			free_memory(rgb);
			return (1);
		}
		i++;
	}
	free_memory(rgb);
	return (0);
}

int	c(t_game **game, char *info)
{
	char	**rgb;
	int		i;
	int		nb;

	if (arg_exist(info, (*game)->c[0]))
		return (1);
	rgb = good_rgb(info);
	if (!rgb)
		return (1);
	i = 0;
	while (rgb[i])
	{
		nb = ft_atoi(rgb[i]);
		if (nb >= 0 && nb <= 255)
			(*game)->c[i] = nb;
		else
		{
			error_handler("RGB format is not valid.");
			free_memory(rgb);
			return (1);
		}
		i++;
	}
	free_memory(rgb);
	return (0);
}
