/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:39:37 by scegla            #+#    #+#             */
/*   Updated: 2026/07/31 18:31:50 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*get_good_info(char *info)
{
	int		j;
	int		count;
	char	*cpy;
	int		fd;

	count = 0;
	j = 0;
	while (info[j] == ' ')
		j++;
	cpy = ft_calloc(sizeof(char), ft_strlen(&info[j]));
	if (!cpy)
		return (NULL);
	while (info[j + count] && info[j + count] != '\n')
	{
		cpy[count] = info[j + count];
		count++;
	}
	fd = open(cpy, O_RDONLY);
	if (fd == -1)
	{
		image_does_not_exist(cpy);
		return (NULL);
	}
	close(fd);
	return (cpy);
}

int	no(t_game **game, char *info)
{
	int		j;
	int		count;
	char	*cpy;

	j = 0;
	count = 0;
	if ((*game)->no)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid data.", 2);
		return (1);
	}
	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	cpy = get_good_info(info);
	if (!cpy)
		return (1);
	(*game)->no = mlx_new_image_from_file((*game)->mlx, cpy,
			&(*game)->texture_width[0], &(*game)->texture_height[0]);
	free(cpy);
	if (!(*game)->no)
		return (1);
	return (0);
}

int	so(t_game **game, char *info)
{
	int		j;
	int		count;
	char	*cpy;

	j = 0;
	count = 0;
	if ((*game)->so)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid data.", 2);
		return (1);
	}
	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	cpy = get_good_info(info);
	if (!cpy)
		return (1);
	(*game)->so = mlx_new_image_from_file((*game)->mlx, cpy,
			&(*game)->texture_width[1], &(*game)->texture_height[1]);
	free(cpy);
	if (!(*game)->so)
		return (1);
	return (0);
}

int	we(t_game **game, char *info)
{
	int		j;
	int		count;
	char	*cpy;

	j = 0;
	count = 0;
	if ((*game)->we)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid data.", 2);
		return (1);
	}
	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	cpy = get_good_info(info);
	if (!cpy)
		return (1);
	(*game)->we = mlx_new_image_from_file((*game)->mlx, cpy,
			&(*game)->texture_width[2], &(*game)->texture_height[2]);
	free(cpy);
	if (!(*game)->we)
		return (1);
	return (0);
}

int	ea(t_game **game, char *info)
{
	int		j;
	int		count;
	char	*cpy;

	j = 0;
	count = 0;
	if ((*game)->ea)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid data.", 2);
		return (1);
	}
	if (!info)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Missing information.", 2);
		return (1);
	}
	cpy = get_good_info(info);
	if (!cpy)
		return (1);
	(*game)->ea = mlx_new_image_from_file((*game)->mlx, cpy,
			&(*game)->texture_width[3], &(*game)->texture_height[3]);
	free(cpy);
	if (!(*game)->ea)
		return (1);
	return (0);
}
