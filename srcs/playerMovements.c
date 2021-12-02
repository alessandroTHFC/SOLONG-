/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   playerMovements.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:46:45 by apangraz          #+#    #+#             */
/*   Updated: 2021/11/16 13:15:54 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	up_down(t_root *game, int keycode);
static int	left_right(t_root *game, int keycode);
static int	valid_move(t_root *game, int x, int y);

int	key_handler(int keycode, t_root *game)
{
	int	allGood;

	if (keycode == 53)
		free_exit(game);
	if (keycode == 13)
		allGood = up_down(game, keycode);
	if (keycode == 1)
		allGood = up_down(game, keycode);
	if (keycode == 0)
		allGood = left_right(game, keycode);
	if (keycode == 2)
		allGood = left_right(game, keycode);
	if (allGood)
		add_graphics(game);
	return (1);
}

static int	up_down(t_root *game, int keycode)
{
	int	x;
	int	y;
	int	check;

	x = game->playerX;
	y = game->playerY;
	if (keycode == 13) //move upwards
	{
		y--;
		if (game->map[y][x] == '1')
			return (0);
		check = valid_move(game, x, y);
		if (!check)
			return (0);
		game->map[y + 1][x] = '0';
	}
	else if (keycode == 1) //move downwards
	{
		y++;
		if (game->map[y][x] == '1')
			return (0);
		check = valid_move(game, x, y);
		if (!check)
			return (0);
		game->map[y - 1][x] = '0';
	}
	printf("Steps Taken: %i\n Potions Left: %i\n", game->stepCounter, game->potions);
	return (1);
}

static int	left_right(t_root *game, int keycode)
{
	int	x;
	int	y;
	int	check;

	x = game->playerX;
	y = game->playerY;
	if (keycode == 0) //move left
	{
		x--;
		if (game->map[y][x] == '1')
			return (0);
		check = valid_move(game, x, y);
		if (!check)
			return (0);
		game->map[y][x + 1] = '0';
	}
	else if (keycode == 2) //move right
	{
		x++;
		if (game->map[y][x] == '1')
			return (0);
		check = valid_move(game, x, y);
		if (!check)
			return (0);
		game->map[y][x - 1] = '0';
	}
	printf("Steps Taken: %i\n Potions Left: %i\n", game->stepCounter, game->potions);
	return (1);
}

static int	valid_move(t_root *game, int x, int y)
{
	if (game->map[y][x] == 'E')
	{
		if (game->potions != 0)
			return (0);
		printf("\e[31m\e[1m\nCongratulations You Win! \e[0m \n");
		free_exit(game);
	}
	if (game->map[y][x] == '0')
	{
		game->map[y][x] = 'P';
		game->playerX = x;
		game->playerY = y;
		game->stepCounter++;
	}
	if (game->map[y][x] == 'C')
	{
		game->map[y][x] = 'P';
		game->playerX = x;
		game->playerY = y;
		game->potions--;
		game->stepCounter++;
	}
	return (1);
}
