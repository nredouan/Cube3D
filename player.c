/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 15:25:46 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/06 15:29:58 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cube3d.h"

t_player	*init_player(void)
{
	t_player	player;
	
	player.x = 1920/2;
	player.y = 1080/2;
	player.width = 5;
	player.height = 5;
}
