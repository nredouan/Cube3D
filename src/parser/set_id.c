/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_id.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:39:37 by scegla            #+#    #+#             */
/*   Updated: 2026/08/01 16:31:31 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

char	*get_good_info(char *info)
{
	int		j;
	char	*cpy;
	int		fd;

	j = 0;
	while (info[j] == ' ')
		j++;
	cpy = cpy_start_to_endl(info, j);
	if (!cpy)
		return (NULL);
	if (is_jpg(cpy))
	{
		free(cpy);
		return (NULL);
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
		error_handler("Invalid data.");
		return (1);
	}
	if (!info)
	{
		error_handler("Missing information.");
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
		error_handler("Invalid data.");
		return (1);
	}
	if (!info)
	{
		error_handler("Missing information.");
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
		error_handler("Invalid data.");
		return (1);
	}
	if (!info)
	{
		error_handler("Missing information.");
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
		error_handler("Invalid data.");
		return (1);
	}
	if (!info)
	{
		error_handler("Missing information.");
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
