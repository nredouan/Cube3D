/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: scegla <scegla@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/06 13:20:18 by scegla            #+#    #+#             */
/*   Updated: 2026/07/07 15:51:21 by scegla           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cube3d.h"

int	ft_tmapsize(t_map *lst)
{
	int		count;
	t_map	*temp;

	if (lst == NULL)
		return (0);
	temp = lst;
	count = 0;
	while (temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

t_map	*ft_lstlast_map(t_map *lst)
{
	t_map	*temp;

	temp = lst;
	if (lst || lst->next)
	{
		while (temp->next)
		{
			temp = temp->next;
		}
		return (temp);
	}
	return (NULL);
}

void	ft_lstadd_back_map(t_map **lst, t_map *new)
{
	t_map	*temp;

	if (lst)
	{
		if (*lst == NULL)
			*lst = new;
		else
		{
			temp = ft_lstlast_map(*lst);
			temp->next = new;
		}
	}
}

t_map	*ft_lstnew_file(char *str)
{
	t_map	*new;

	new = ft_calloc(sizeof(t_map), 1);
	if (new)
	{
		new->map = ft_strdup(str);
		if (!new->map)
			return (NULL);
		new->next = NULL;
		return (new);
	}
	return (NULL);
}

void	free_tmap(t_map **map)
{
	t_map	*tmp;

	if (!map || !*map)
		return ;
	while (*map)
	{
		tmp = (*map)->next;
		free((*map)->map);
		free(*map);
		*map = tmp;
	}
	*map = NULL;
}
