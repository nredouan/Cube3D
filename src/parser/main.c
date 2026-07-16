/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 12:10:07 by scegla            #+#    #+#             */
/*   Updated: 2026/07/16 11:05:40 by scegla           ###   ########.fr       */
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
	mlx = ft_calloc(sizeof(t_mlx), 1);
	if (!mlx)
		return (1);
	mlx->addr = mlx_init();
	mlx_window_create_info *win;
	win = ft_calloc(sizeof(mlx_window_create_info), 1);
	if (!win)
		return (1);
	win->height = 500;
	win->width = 500;
	int	ds[1];
	ds[0] = 64;
	win->title = "caca";
	mlx->wall_no = mlx_new_image_from_file(mlx->addr, data->no, ds, ds);
	mlx->win = mlx_new_window(mlx->addr, win);
	mlx_put_image_to_window(mlx->addr, mlx->win, mlx->wall_no, 0, 0);
	mlx_loop(mlx->addr);
	free_data(&data);
	return (0);
}
