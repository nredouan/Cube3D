/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:45:26 by scegla            #+#    #+#             */
/*   Updated: 2026/07/15 16:46:19 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

void	free_memory(char **s)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return ;
}

int	until_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			return (i);
		}
		i++;
	}
	return (i);
}

void	finish_gnl(int fd)
{
	char	*str;

	str = get_next_line(fd);
	while (str)
	{
		free(str);
		str = get_next_line(fd);
	}
	free(str);
}

void	free_data(t_data **data)
{
	free((*data)->so);
	free((*data)->ea);
	free((*data)->no);
	free((*data)->we);
	if ((*data)->map)
		free_memory((*data)->map);
	free(*data);
}

void	is_cub(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '.')
		i++;
	if (strncmp(&str[i], ".cub", 4))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Your map file need to be a .cub extension", 2);
		exit (1);
	}
}
