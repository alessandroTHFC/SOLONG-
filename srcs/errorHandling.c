/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errorHandling.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:46:45 by apangraz          #+#    #+#             */
/*   Updated: 2021/11/16 13:15:21 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	chk_walls(t_root *game);
static int	horizontal(t_root *game);
static int	vertical(t_root *game);
void		valid_chars(t_root *game);
static void	chk_count(t_root *game, int h, int w);

void	error_chkr(t_root *game)
{
	chk_walls(game);
	valid_chars(game);
}

static void	chk_walls(t_root *game)
{
	int	vWalls;
	int	hWalls;

	vWalls = vertical(game);
	hWalls = horizontal(game);
	if (!vWalls || !hWalls)
	{	
		printf("\e[31m\e[1mError\nMap is missing walls, map unacceptable \e[0m \n");
		free_exit(game);
	}
}

static int	horizontal(t_root *game)
{
	int	w;
	int	i;

	w = game->mapWidth;
	i = 0;
	while (i < w)
	{
		if (!(game->map[0][i] == '1'
			&& game->map[game->mapHeight - 1][i] == '1'))
			return (0);
		i++;
	}
	return (1);
}

static int	vertical(t_root *game)
{
	int	h;
	int	w;

	h = 0;
	w = game->mapWidth;
	while (h < game->mapHeight)
	{
		if (!(game->map[h][0] == '1' && game->map[h][w - 1] == '1'))
			return (0);
		h++;
	}
	return (1);
}

void	valid_chars(t_root *game)
{
	int	h;
	int	w;

	h = 0;
	while (h < game->mapHeight - 1)
	{
		w = 0;
		while (w <= game->mapWidth)
		{
			chk_count(game, h, w);
			w++;
		}
		h++;
	}
	if (!(game->plyrcount == 1 && game->colcount > 1 && game->exitcount == 1))
	{
		printf("\e[31m\e[1mError\nGame components incorrect,only 1 player, 1 exit allowed, potions need to be more than one! \e[0m \n");
		free_exit(game);
	}	
}

static void	chk_count(t_root *game, int h, int w)
{
	if (game->map[h][w] != '1' &&
		game->map[h][w] != '0' &&
		game->map[h][w] != 'P' &&
		game->map[h][w] != 'E' &&
		game->map[h][w] != 'C' &&
		game->map[h][w] != '\n')
	{
		printf("\e[31m\e[1mError\nUnknown characters in the map!! \e[0m \n");
		printf("this char is failing %c\n", game->map[h][w]);
		free_exit(game);
	}
	if (game->map[h][w] == 'C')
		game->colcount++;
	if (game->map[h][w] == 'P')
		game->plyrcount++;
	if (game->map[h][w] == 'E')
		game->exitcount++;
}
