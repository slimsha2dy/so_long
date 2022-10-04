/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:39:14 by hwichoi           #+#    #+#             */
/*   Updated: 2022/10/04 19:33:03 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	image_set(t_img *img, t_game *game)
{
	int	img_wid;
	int	img_hei;

	img->field = mlx_xpm_file_to_image(game->mlx, \
			"./images/field.xpm", &img_wid, &img_hei);
	img->wall = mlx_xpm_file_to_image(game->mlx, \
			"./images/tree.xpm", &img_wid, &img_hei);
	img->c_img = mlx_xpm_file_to_image(game->mlx, \
			"./images/item.xpm", &img_wid, &img_hei);
	img->e_img = mlx_xpm_file_to_image(game->mlx, \
			"./images/stone.xpm", &img_wid, &img_hei);
	img->p_img = mlx_xpm_file_to_image(game->mlx, \
			"./images/thomas_face.xpm", &img_wid, &img_hei);
	return ;
}
