/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:39:37 by scegla            #+#    #+#             */
/*   Updated: 2026/07/16 12:32:58 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	no(t_game **game, char *info)
{
	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	// if (access(info, R_OK) == -1)
	// {
	// 	ft_putendl_fd("Error", 2);
	// 	ft_putendl_fd("A image is not accessible.", 2);
	// 	return (1);
	// }
	(*game)->no = ft_strdup(info);
	if (!(*game)->no)
		return (1);
	return (0);
}

int	so(t_game **game, char *info)
{
	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	// if (access(info, R_OK) == -1)
	// {
	// 	ft_putendl_fd("Error", 2);
	// 	ft_putendl_fd("A image is not accessible.", 2);
	// 	return (1);
	// }
	(*game)->so = ft_strdup(info);
	if (!(*game)->so)
		return (1);
	return (0);
}

int	we(t_game **game, char *info)
{
	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	// if (access(info, R_OK) == -1)
	// {
	// 	ft_putendl_fd("Error", 2);
	// 	ft_putendl_fd("A image is not accessible.", 2);
	// 	return (1);
	// }
	(*game)->we = ft_strdup(info);
	if (!(*game)->we)
		return (1);
	return (0);
}

int	ea(t_game **game, char *info)
{
	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	// if (access(info, R_OK) == -1)
	// {
	// 	ft_putendl_fd("Error", 2);
	// 	ft_putendl_fd("A image is not accessible.", 2);
	// 	return (1);
	// }
	(*game)->ea = ft_strdup(info);
	if (!(*game)->ea)
		return (1);
	return (0);
}
