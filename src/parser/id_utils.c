/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:50:49 by scegla            #+#    #+#             */
/*   Updated: 2026/08/01 11:40:15 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	image_does_not_exist(char *cpy)
{
	free(cpy);
	error_handler("Image not accessible.");
}

int	is_jpg(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0 && str[i] != '.')
		i--;
	if (strcmp(&str[i], ".jpg"))
	{
		if (strcmp(&str[i], ".jpeg"))
		{
			error_handler("The texture need to be a jpg/jpeg extension");
			return (1);
		}
	}
	return (0);
}

char	*cpy_start_to_endl(char *info, int j)
{
	int		count;
	char	*cpy;

	cpy = ft_calloc(sizeof(char), ft_strlen(&info[j]));
	if (!cpy)
		return (NULL);
	count = 0;
	while (info[j + count] && info[j + count] != '\n')
	{
		cpy[count] = info[j + count];
		count++;
	}
	return (cpy);
}

void	*not_digit(char **rgb)
{
	error_handler("Rgb need to be only number.");
	free_memory(rgb);
	return (NULL);
}

int	error_in_info(char *str, int fd, int i)
{
	free(str);
	finish_gnl(fd);
	if (i)
		error_handler("Wrong identifier in map.");
	return (1);
}
