/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/03 21:27:37 by hwichoi           #+#    #+#             */
/*   Updated: 2022/10/17 16:09:09 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strjoin_sl(char *s1, char *s2)
{
	char	*buf;
	int		size;
	int		i;

	size = ft_strlen(s1) + ft_strlen(s2);
	buf = (char *)malloc(sizeof(char) * size);
	if (buf == 0)
		return (0);
	i = 0;
	while (*s1 && *s1 != '\n' && i < size)
	{
		buf[i++] = *s1;
		s1++;
	}
	while (*s2 && i < size)
	{
		buf[i++] = *s2;
		s2++;
	}
	buf[i] = 0;
	return (buf);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned char	to_find;
	int				i;
	unsigned char	*buf;

	to_find = (unsigned char)c;
	i = 0;
	buf = (unsigned char *)s;
	while (buf[i] != 0)
	{
		if (buf[i] == to_find)
			return ((char *)&buf[i]);
		i++;
	}
	if (buf[i] == to_find)
		return ((char *)&buf[i]);
	return (0);
}

void	check_game(t_game *game)
{
	game->mv_cnt++;
	printf("Number of movement: %d\n", game->mv_cnt);
	if (game->map_str[game->p_loc] == 'C')
	{
		game->c_cnt++;
		game->map_str[game->p_loc] = '0';
	}
	if (game->c_cnt == game->all_c && game->map_str[game->p_loc] == 'E')
	{
		printf("Game clear, total %d movement\n", game->mv_cnt);
		esc_press(game);
	}
}

void	print_err(const char *str)
{
	printf("%s\n", str);
	exit(0);
}
