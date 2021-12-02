/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgInitialiser.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:46:45 by apangraz          #+#    #+#             */
/*   Updated: 2021/11/16 12:46:45 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	putplayer(t_root *game, int h, int w);
void	putpotion(t_root *game, int h, int w);

void	img_init(t_root *game)
{
	int	x;
	int	y;

	game->ground = mlx_xpm_file_to_image(game->mlxptr,
			"img/Ground.xpm", &x, &y);
	game->tree = mlx_xpm_file_to_image(game->mlxptr, "img/Tree.xpm", &x, &y);
	game->player = mlx_xpm_file_to_image(game->mlxptr, "img/Link.xpm", &x, &y);
	game->exit = mlx_xpm_file_to_image(game->mlxptr, "img/Tent.xpm", &x, &y);
	game->collectable = mlx_xpm_file_to_image(game->mlxptr,
			"img/Potion.xpm", &x, &y);
}

void	add_graphics(t_root *game)
{
	int	h;
	int	w;

	game->potions = 0;
	h = 0;
	while (h < game->mapHeight)
	{
		w = 0;
		while (game->map[h][w])
		{
			if (game->map[h][w] == '1')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->tree, w * 40, h * 40);
			if (game->map[h][w] == 'C')
				putpotion(game, h, w);
			if (game->map[h][w] == 'P')
				putplayer(game, h, w);
			if (game->map[h][w] == 'E')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->exit, w * 40, h * 40);
			if (game->map[h][w] == '0')
				mlx_put_image_to_window(game->mlxptr,
					game->winptr, game->ground, w * 40, h * 40);
			w++;
		}
		h++;
	}
}

void	putplayer(t_root *game, int h, int w)
{
	mlx_put_image_to_window(game->mlxptr,
		game->winptr, game->player, w * 40, h * 40);
	game->playerY = h;
	game->playerX = w;
}

void	putpotion(t_root *game, int h, int w)
{
	mlx_put_image_to_window(game->mlxptr,
		game->winptr, game->collectable, w * 40, h * 40);
	game->potions++;
}
