/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fandc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/07 16:57:00 by scegla            #+#    #+#             */
/*   Updated: 2026/07/07 16:57:38 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	f(t_data **data, char *info)
{
	char	**rgb;
	int		i;
	int		nb;

	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	i = 0;
	rgb = ft_split(info, ',');
	while (rgb[i])
		i++;
	if (i > 3)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Too much arg in floor.", 2);
		free_memory(rgb);
		return (1);
	}
	i = 0;
	while (rgb[i])
	{
		nb = ft_atoi(rgb[i]);
		if (nb >= 0 && nb <= 255)
			(*data)->c[i] = nb;
		else
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Invalid information.", 2);
			free_memory(rgb);
			return (1);
		}
		i++;
	}
	free_memory(rgb);
	return (0);
}

int	c(t_data **data, char *info)
{
	char	**rgb;
	int		i;
	int		nb;

	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	i = 0;
	rgb = ft_split(info, ',');
	while (rgb[i])
		i++;
	if (i > 3)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Too much arg in ceiling.", 2);
		free_memory(rgb);
		return (1);
	}
	i = 0;
	while (rgb[i])
	{
		nb = ft_atoi(rgb[i]);
		if (nb >= 0 && nb <= 255)
			(*data)->c[i] = nb;
		else
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Invalid information.", 2);
			free_memory(rgb);
			return (1);
		}
		i++;
	}
	free_memory(rgb);
	return (0);
}
