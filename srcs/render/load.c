/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 12:51:31 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/08 12:54:44 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

size_t	find_index(char *s, char c)
{
	size_t	i;

	if (!s)
		return (-1);
	i = 0;
	while (*s)
	{
		if (*s == c)
			return (i);
		s++;
		i++;
	}
	return (-1);
}

t_element	load_element(t_game *game, size_t index[2])
{
	t_map_element	c;

	c = game->map.map[locate_position(game, index)];
	return (find_index(MAP_ELEMENTS, c));
}

uint32_t	load_color(t_game *game, size_t index[2], t_element element)
{
	float		ratio;
	size_t		position[2];
	uint32_t	color;

	ratio = (float)game->sprites[element].size[WIDTH] / TILE_SIZE;
	position[X] = index[X] * ratio;
	position[Y] = index[Y] * game->sprites[element].size[WIDTH] * ratio;
	color = game->sprites[element].data[position[X] + position[Y]];
	return (color);
}
