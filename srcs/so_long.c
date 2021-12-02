/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apangraz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 12:46:45 by apangraz          #+#    #+#             */
/*   Updated: 2021/11/16 12:47:15 by apangraz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	*ft_memset(void *s, int c, size_t len);

int	main(int argc, char **argv)
{
	t_root	game;

	if (argc != 2)
		return (0);
	ft_memset(&game, 0, sizeof(t_root));
	read_map(&game, argv);
	error_chkr(&game);
	game.mlxptr = mlx_init();
	game.winptr = mlx_new_window(game.mlxptr, (game.mapWidth * 40),
			(game.mapHeight * 40), "solong");
	img_init(&game);
	add_graphics(&game);
	mlx_key_hook(game.winptr, key_handler, &game);
	mlx_hook(game.winptr, 17, 0, (void *)exit, 0);
	mlx_loop(game.mlxptr);
}

int	free_exit(t_root *game)
{
	int	row;

	mlx_destroy_window(game->mlxptr, game->winptr);
	free(game->mlxptr);
	row = 0;
	while (row < game->mapHeight - 1)
		free(game->map[row++]);
	free(game->map);
	exit(0);
}

static void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (len--)
		*str++ = (unsigned char)c;
	return (s);
}
