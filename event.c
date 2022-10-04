/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 18:50:48 by hwichoi           #+#    #+#             */
/*   Updated: 2022/10/04 22:40:19 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	esc_press(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	w_press(t_game *game)
{
	int		i;
	t_img	img;

	image_set(&img, game);
	i = game->p_loc - game->wid;
	if (game->map_str[i] && game->map_str[i] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, img.p_img, \
			i % game->wid * 64, i / game->wid * 64);
		mlx_put_image_to_window(game->mlx, game->win, img.field, \
			game->p_loc % game->wid * 64, game->p_loc / game->wid * 64);
		if (game->map_str[game->p_loc] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, img.e_img, \
				game->p_loc % game->wid * 64, game->p_loc / game->wid * 64);
		game->p_loc = i;
		check_game(game);
	}
}

void	a_press(t_game *game)
{
	int		i;
	t_img	img;

	image_set(&img, game);
	i = game->p_loc - 1;
	if (game->map_str[i] && game->map_str[i] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, img.p_img, \
			i % game->wid * 64, i / game->wid * 64);
		mlx_put_image_to_window(game->mlx, game->win, img.field, \
			game->p_loc % game->wid * 64, game->p_loc / game->wid * 64);
		if (game->map_str[game->p_loc] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, img.e_img, \
				game->p_loc % game->wid * 64, game->p_loc / game->wid * 64);
		game->p_loc = i;
		check_game(game);
	}
}

void	s_press(t_game *game)
{
	int		i;
	t_img	img;

	image_set(&img, game);
	i = game->p_loc + game->wid;
	if (game->map_str[i] && game->map_str[i] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, img.p_img, \
			i % game->wid * 64, i / game->wid * 64);
		mlx_put_image_to_window(game->mlx, game->win, img.field, \
			game->p_loc % game->wid * 64, game->p_loc / game->wid * 64);
		if (game->map_str[game->p_loc] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, img.e_img, \
				game->p_loc % game->wid * 64, game->p_loc / game->wid * 64);
		game->p_loc = i;
		check_game(game);
	}
}

void	d_press(t_game *game)
{
	int		i;
	t_img	img;

	image_set(&img, game);
	i = game->p_loc + 1;
	if (game->map_str[i] && game->map_str[i] != '1')
	{
		mlx_put_image_to_window(game->mlx, game->win, img.p_img, \
			i % game->wid * 64, i / game->wid * 64);
		mlx_put_image_to_window(game->mlx, game->win, img.field, \
			game->p_loc % game->wid * 64, game->p_loc / game->wid * 64);
		if (game->map_str[game->p_loc] == 'E')
			mlx_put_image_to_window(game->mlx, game->win, img.e_img, \
				game->p_loc % game->wid * 64, game->p_loc / game->wid * 64);
		game->p_loc = i;
		check_game(game);
	}
}
