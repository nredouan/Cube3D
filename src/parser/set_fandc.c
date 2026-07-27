/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fandc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:57:00 by scegla            #+#    #+#             */
/*   Updated: 2026/07/23 15:32:32 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	**good_rgb(char *info)
{
	int		i;
	char	**rgb;

	i = 0;
	rgb = ft_split(info, ',');
	while (rgb[i])
		i++;
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

void	invalid_info(void)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Invalid information.", 2);
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
