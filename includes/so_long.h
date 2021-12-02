#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include "get_next_line.h"
# include "../minilibx/mlx.h"

typedef struct s_root
{
	int	fd;
	char	**map;
	int	mapHeight;
	int	mapWidth;

	int	plyrcount;
	int	colcount; //counting collectables for error check
	int	exitcount;

	void	*ground;
	void	*tree;
	void	*player;
	void	*exit;
	void	*collectable; //img ptr

	void	*mlxptr;
	void	*winptr;

	int	playerX;
	int	playerY;
	int	potions; //to be decremented upon collection for valid exit
	int	stepCounter;
}	t_root;

int	free_exit(t_root *game);
void	error_chkr(t_root *game);
int	read_map(t_root *game, char **argv);
void	img_init(t_root *game);
void	add_graphics(t_root *game);
int		key_handler(int key, t_root *game);

#endif
