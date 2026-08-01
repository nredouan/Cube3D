/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 16:45:26 by scegla            #+#    #+#             */
/*   Updated: 2026/08/01 13:05:23 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	error_handler(char *str)
{
	ft_putendl_fd("Error", 2);
	ft_putendl_fd(str, 2);
}

void	free_memory(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return ;
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

void	is_cub(char *str)
{
	int	i;

	i = ft_strlen(str);
	while (i > 0 && str[i] != '.')
		i--;
	if (strcmp(&str[i], ".cub"))
	{
		error_handler("Your map file need to be a .cub extension");
		exit (1);
	}
}
