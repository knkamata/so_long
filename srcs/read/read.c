/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kkamata <kkamata@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/06 11:49:21 by kkamata           #+#    #+#             */
/*   Updated: 2021/10/06 22:38:05 by kkamata          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_bool	end_read_berfile(char *line, int fd, t_bool status)
{
	free(line);
	close(fd);
	return (status);
}

t_bool	read_berfile(t_game *game)
{
	char	*line;
	int		fd;

	init_map(game);
	if (!get_map_matrix(game))
		return (error_msg(ERRMSG_INVMAP));
	fd = open(game->map.path_to_file, O_RDONLY);
	while (get_next_line_beta(fd, &line) > 0)
	{
		if (!new_map(game, line))
			return (FALSE);
		free(line);
	}
	return(end_read_berfile(line, fd, TRUE));
}