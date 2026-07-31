/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nredouan <nredouan@student.42angouleme.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/31 15:19:46 by nredouan          #+#    #+#             */
/*   Updated: 2026/07/31 16:16:47 by nredouan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	window_hook(int event, void *param)
{
	if (event == 0)
		mlx_loop_end((mlx_context)param);
}
