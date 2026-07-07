/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:10:07 by scegla            #+#    #+#             */
/*   Updated: 2026/07/07 16:11:15 by scegla           ###   ########.fr       */
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

int map_valid(t_data **data, int fd)
{
	char	*str;
	int		nb = 0;
	const t_set_id	list_id[] = {{"NO", no}, {"SO", so}, {"WE", we},
	{"EA", ea}, {"F", f}, {"C", c}, {NULL, NULL}};
	int		i;

	str = get_next_line(fd);
	if (!str)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Map is empty.", 2);
		return (1);
	}
	while (str)
	{
		i = 0;
		while (str && str[0] == '\n')
		{
			free(str);
			str = get_next_line(fd);
		}
		while (list_id[i].type)
		{
			if (!ft_strncmp(str, list_id[i].type, ft_strlen(list_id[i].type)))
			{
				if (list_id[i].f(data, &str[until_space(str)]))
					return (1);
				nb++;
				break ;
			}
			i++;
		}
		if (!list_id[i].type)
		{
			ft_putendl_fd("Error", 2);
			ft_putendl_fd("Wrong identifier in map.", 2);
			return (1);
		}
		if (nb == 6)
		{
			(*data)->map = get_map(fd);
			free(str);
			if (!(*data)->map)
					return (1);
			break ;
		}
		free(str);
		str = get_next_line(fd);
	}
	return (0);
}

void	free_data(t_data **data)
{
	free((*data)->so);
	free((*data)->ea);
	free((*data)->no);
	free((*data)->we);
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

void	print_data(t_data *data)
{
	int i = 0;

	while (i < 3)
	{
		printf("C == %d\n", data->c[i]);
		i++;
	}
	i = 0;
	while (i < 3)
	{
		printf("F == %d\n", data->f[i]);
		i++;
	}
	printf("\nEA == %s\n", data->ea);
	printf("SO == %s\n", data->so);
	printf("NO == %s\n", data->no);
	printf("WE == %s\n", data->we);
	i = 0;
	while (data->map[i])
	{
		printf("%s", data->map[i]);
		i++;
	}
}

int main(int ac, char **av)
{
	int		fd;
	t_data	*data;

	if (ac != 2)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Wrong number of arguments.", 2);
		return (1);
	}
	is_cub(av[1]);
	fd = open(av[1], O_RDONLY);
	if (fd < 0 || fd > 1023)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Your file doesn't exist.", 2);
		return (1);
	}
	data = ft_calloc(sizeof(t_data), 1);
	if (!data)
		return (1);
	map_valid(&data, fd);
	parser(&data);
	print_data(data);
	free_data(&data);
	return (0);
}
