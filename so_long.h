/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 17:16:46 by hwichoi           #+#    #+#             */
/*   Updated: 2022/10/04 22:40:34 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include "./mlx/mlx.h"
# include "./get_next_line/get_next_line.h"

# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_ESC 53

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		wid;
	int		hei;
	int		p_loc;
	int		mv_cnt;
	int		c_cnt;
	int		all_c;
	char	*map_str;
}	t_game;

typedef struct s_img
{
	void	*field;
	void	*wall;
	void	*c_img;
	void	*e_img;
	void	*p_img;
}	t_img;

char	*get_line(char *filename, t_game *game);
void	map_set(char *map_str, t_game *game, t_img *img);
void	map_init(char *filename, t_game *game, t_img *img);

int		elem_chk_ret_c(t_game *game);
int		wall_chk(t_game *game);
void	other_chk(t_game *game);
void	map_chk(t_game *game);

void	image_set(t_img *img, t_game *game);

char	*ft_strjoin_with_free(char *s1, char *s2);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
void	print_err(const char *s);
void	check_game(t_game *game);

int		esc_press(t_game *game);
void	w_press(t_game *game);
void	a_press(t_game *game);
void	s_press(t_game *game);
void	d_press(t_game *game);

#endif
