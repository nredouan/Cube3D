/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:39:37 by scegla            #+#    #+#             */
/*   Updated: 2026/07/15 16:06:15 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	no(t_data **data, char *info)
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
	(*data)->no = ft_strdup(info);
	if (!(*data)->no)
		return (1);
	return (0);
}

int	so(t_data **data, char *info)
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
	(*data)->so = ft_strdup(info);
	if (!(*data)->so)
		return (1);
	return (0);
}

int	we(t_data **data, char *info)
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
	(*data)->we = ft_strdup(info);
	if (!(*data)->we)
		return (1);
	return (0);
}

int	ea(t_data **data, char *info)
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
	(*data)->ea = ft_strdup(info);
	if (!(*data)->ea)
		return (1);
	return (0);
}
