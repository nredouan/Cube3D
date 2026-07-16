/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:10:07 by scegla            #+#    #+#             */
/*   Updated: 2026/07/16 11:07:56 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

// void	print_data(t_data *data)
// {
// 	int	i;

// 	i = 0;
// 	while (i < 3)
// 	{
// 		printf("F == %d\n", data->f[i]);
// 		i++;
// 	}
// 	i = 0;
// 	while (i < 3)
// 	{
// 		printf("C == %d\n", data->c[i]);
// 		i++;
// 	}
// 	printf("\nEA == %s\n", data->ea);
// 	printf("SO == %s\n", data->so);
// 	printf("NO == %s\n", data->no);
// 	printf("WE == %s\n", data->we);
// 	i = 0;
// 	while (data->map[i])
// 	{
// 		printf("%s", data->map[i]);
// 		i++;
// 	}
// }

int	main(int ac, char **av)
{
	int		fd;
	t_data	*data;
	t_mlx	*mlx;

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
	data->map = NULL;
	if (map_valid(&data, fd))
	{
		free_data(&data);
		return (1);
	}
	parser(&data);
	// print_data(data);
	free_data(&data);
	return (0);
}
