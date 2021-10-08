/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 22:36:42 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/09 05:48:24 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static t_bool	load_map_col(t_game *game, int fd)
{
	char	*line;

	if (get_next_line_beta(fd, &line) < 1)
		return (FALSE);
	game->map.matrix[COL] = (int64_t)ft_strlen(line);
	free(line);
	return (TRUE);
}

t_bool	load_map_matrix(t_game *game)
{
	int		fd;
	char	*line;

	fd = open(game->map.path_to_file, O_RDONLY);
	if (!load_map_col(game, fd))
		return (FALSE);
	game->map.matrix[ROW]++;
	while (get_next_line_beta(fd, &line) >= 0)
	{
		if (!line)
			break ;
		game->map.matrix[ROW]++;
		if (game->map.matrix[COL] != (int64_t)ft_strlen(line))
			return (end_read_berfile(line, fd, FALSE));
		free(line);
	}
	game->map.size[WIDTH] = game->map.matrix[COL] * TILE_SIZE;
	game->map.size[HEIGHT] = game->map.matrix[ROW] * TILE_SIZE;
	return (end_read_berfile(line, fd, TRUE));
}
