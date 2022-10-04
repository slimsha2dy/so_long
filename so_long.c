/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:12:01 by hwichoi           #+#    #+#             */
/*   Updated: 2022/10/04 22:39:06 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_cnt(t_game *game)
{
	game->mv_cnt = 0;
	game->c_cnt = 0;
}

int	key_press(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		esc_press(game);
	if (key_code == KEY_W)
		w_press(game);
	if (key_code == KEY_A)
		a_press(game);
	if (key_code == KEY_S)
		s_press(game);
	if (key_code == KEY_D)
		d_press(game);
	return (0);
}

int	main(int ac, char **av)
{
	t_game	game;
	t_img	img;

	game.mlx = mlx_init();
	set_cnt(&game);
	image_set(&img, &game);
	map_init(av[1], &game, &img);
	mlx_hook(game.win, X_EVENT_KEY_PRESS, 0, &key_press, &game);
	mlx_hook(game.win, X_EVENT_KEY_EXIT, 0, &esc_press, &game);
	mlx_loop(game.mlx);
}
