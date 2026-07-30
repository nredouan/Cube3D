/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fandc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:57:00 by scegla            #+#    #+#             */
/*   Updated: 2026/07/30 12:37:45 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	*not_digit(char **rgb)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Rgb need to be only number.", 2);
	free_memory(rgb);
	return (NULL);
}

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
			if (rgb[i][j] != '\n' && !ft_isdigit(rgb[i][j]))
				return (not_digit(rgb));
			j++;
		}
		i++;
	}
	if (i > 3)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Too much arg in floor.", 2);
		free_memory(rgb);
		return (NULL);
	}
	return (rgb);
}

int	arg_exist(char *info)
{
	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	return (0);
}

int	f(t_game **game, char *info)
{
	char	**rgb;
	int		i;
	int		nb;

	if (arg_exist(info))
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
			invalid_info();
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

	if (arg_exist(info))
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
			invalid_info();
			free_memory(rgb);
			return (1);
		}
		i++;
	}
	free_memory(rgb);
	return (0);
}
