/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hwichoi <hwichoi@student.42seoul.k>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/26 16:23:47 by hwichoi           #+#    #+#             */
/*   Updated: 2022/07/26 16:04:12 by hwichoi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	is_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i] > 0)
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*line_ret(char **str, int i)
{
	char	*ret;
	char	*buf;
	int		cnt;

	ret = (char *)malloc(sizeof(char) * i + 2);
	if (ret == 0)
	{
		gnl_free(str);
		return (0);
	}
	cnt = -1;
	while (++cnt <= i)
		ret[cnt] = (*str)[cnt];
	ret[cnt] = 0;
	buf = ft_strdup(&(*str)[i + 1]);
	if (buf == 0)
	{
		gnl_free(str);
		gnl_free(&ret);
		return (0);
	}
	gnl_free(str);
	*str = buf;
	return (ret);
}

char	*ret_left(char **str)
{
	char	*ret;

	if (*str == 0)
		return (0);
	if (**str == 0)
	{
		gnl_free(str);
		return (0);
	}
	if (is_nl(*str) > -1)
		ret = line_ret(str, is_nl(*str));
	else
	{
		ret = ft_strdup(*str);
		gnl_free(str);
	}
	if (ret == 0)
	{
		gnl_free(&ret);
		return (0);
	}
	return (ret);
}

char	*strappend(char *str1, char *str2)
{
	char	*dest;
	size_t	s1;
	size_t	s2;

	if (str1 == 0 && str2 == 0)
		return (0);
	if (str1 == 0 || str1 == 0)
	{
		if (str2 != 0)
			return (ft_strdup(str2));
		return (str1);
	}
	s1 = ft_strlen(str1);
	s2 = ft_strlen(str2);
	dest = (char *)malloc(s1 + s2 + 1);
	if (dest == 0)
		return (0);
	ft_strlcpy(dest, str1, s1 + 1);
	ft_strlcpy(dest + s1, str2, s2 + 1);
	gnl_free(&str1);
	return (dest);
}

char	*get_next_line(int fd)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*backup;
	int			readsize;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (0);
	readsize = read(fd, buf, BUFFER_SIZE);
	while (readsize > 0)
	{
		buf[readsize] = 0;
		backup = strappend(backup, buf);
		if (is_nl(backup) > -1)
			return (line_ret(&backup, is_nl(backup)));
		readsize = read(fd, buf, BUFFER_SIZE);
	}
	if (readsize < 0)
	{
		gnl_free(&backup);
		return (0);
	}
	return (ret_left(&backup));
}
