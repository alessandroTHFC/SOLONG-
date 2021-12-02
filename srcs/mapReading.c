/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapReading.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:46:45 by apangraz          #+#    #+#             */
/*   Updated: 2021/11/16 12:46:45 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	get_width(char *str);
static int	addnewline(t_root *game, char *line);

int	read_map(t_root *game, char **argv)
{
	char	*read;

	game->fd = open(argv[1], O_RDONLY);
	if (game->fd < 0)
		return (0);
	while (1)
	{
		read = get_next_line(game->fd);
		if (!addnewline(game, read))
			break ;
	}
	close (game->fd);
	game->mapWidth = get_width(game->map[0]);
	return (1);
}

static int	addnewline(t_root *game, char *line)
{
	char	**tmp;
	int		i;

	if (!line)
		return (0);
	i = 0;
	game->mapHeight++;
	tmp = (char **)malloc(sizeof(char *) * (game->mapHeight + 1));
	tmp[game->mapHeight] = NULL;
	while (i < game->mapHeight - 1)
	{
		tmp[i] = game->map[i];
		i++;
	}
	tmp[i] = line;
	if (game->map)
		free(game->map);
	game->map = tmp;
	return (1);
}

static int	get_width(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	if (str[i -1] == '\n')
		i--;
	return (i);
}
