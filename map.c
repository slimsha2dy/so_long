/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:07:42 by hwichoi           #+#    #+#             */
/*   Updated: 2022/10/17 16:10:08 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_line(char *filename, t_game *game)
{
	int		fd;
	char	*line;
	char	*buf;

	fd = open(filename, O_RDONLY);
	game->hei = 0;
	game->map_str = ft_strdup("");
	line = get_next_line(fd);
	game->wid = ft_strlen(line) - 1;
	while (line)
	{
		game->hei++;
		buf = game->map_str;
		game->map_str = ft_strjoin_sl(buf, line);
		free(line);
		free(buf);
		line = get_next_line(fd);
	}
	if (game->map_str[ft_strlen(game->map_str) - 1] == '\n')
		game->map_str[ft_strlen(game->map_str) - 1] = '\0';
	close(fd);
	return ;
}

void	map_set(char *map_str, t_game *game, t_img *img)
{
	int	wid;
	int	hei;

	hei = -1;
	while (++hei < game->hei)
	{
		wid = -1;
		while (++wid < game->wid)
		{
			mlx_put_image_to_window(game->mlx, game->win, \
				img->field, wid * 64, hei * 64);
			if (*map_str == '1')
				mlx_put_image_to_window(game->mlx, game->win, \
					img->wall, wid * 64, hei * 64);
			if (*map_str == 'C')
				mlx_put_image_to_window(game->mlx, game->win, \
					img->c_img, wid * 64, hei * 64);
			if (*map_str == 'E')
				mlx_put_image_to_window(game->mlx, game->win, \
					img->e_img, wid * 64, hei * 64);
			if (*(map_str++) == 'P')
				mlx_put_image_to_window(game->mlx, game->win, \
					img->p_img, wid * 64, hei * 64);
		}
	}
}

void	map_init(char *filename, t_game *game, t_img *img)
{
	get_line(filename, game);
	map_chk(game);
	game->win = mlx_new_window(game->mlx, \
		game->wid * 64, game->hei * 64, "so_long");
	map_set(game->map_str, game, img);
	return ;
}
