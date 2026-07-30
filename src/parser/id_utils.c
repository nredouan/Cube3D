/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   id_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 14:50:49 by scegla            #+#    #+#             */
/*   Updated: 2026/07/30 14:51:08 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	image_does_not_exist(char *cpy)
{
	free(cpy);
	ft_putendl_fd("Error", 2);
	ft_putendl_fd("Image not accessible.", 2);
}
