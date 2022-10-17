/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/04 20:30:21 by hwichoi           #+#    #+#             */
/*   Updated: 2022/10/17 15:47:10 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"	

int	elem_chk_ret_c(t_game *game)
{
	int	i;
	int	p;
	int	e;
	int	c;

	i = 0;
	p = 0;
	e = 0;
	c = 0;
	while (game->map_str[i])
	{
		if (game->map_str[i] == 'P')
		{
			game->p_loc = i;
			p++;
		}
		if (game->map_str[i] == 'E')
			e++;
		if (game->map_str[i] == 'C')
			c++;
		i++;
	}
	if (p != 1 || e < 1 || c < 1)
		print_err("Map must have at least one 'C' and 'E' and \
only one 'P'\n");
	return (c);
}

int	wall_chk(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_str[i] && game->map_str[i] != '\n')
	{
		if (i < game->wid)
		{
			if (game->map_str[i] != '1')
				return (0);
		}
		if ((i % game->wid) == 0 || (i % game->wid) == game->wid - 1)
		{
			if (game->map_str[i] != '1')
				return (0);
		}
		if (i > (int)ft_strlen(game->map_str) - game->wid)
		{
			if (game->map_str[i] != '1')
				return (0);
		}
		i++;
	}
	return (1);
}

void	other_chk(t_game *game)
{
	int	i;

	i = 0;
	while (game->map_str[i] && game->map_str[i] != '\n')
	{
		if (ft_strchr("10PCE", game->map_str[i]) == 0)
			print_err("There is invalid character\n");
		i++;
	}
}

void	map_chk(t_game *game)
{
	if ((game->wid * game->hei) != (int)ft_strlen(game->map_str))
		print_err("Map must be rectangle\n");
	game->all_c = elem_chk_ret_c(game);
	if (wall_chk(game) == 0)
		print_err("Map must be closed by walls\n");
	other_chk(game);
}
