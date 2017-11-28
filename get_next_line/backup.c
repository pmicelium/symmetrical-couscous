/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pmiceli <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 10:46:55 by pmiceli           #+#    #+#             */
/*   Updated: 2017/11/28 16:22:24 by pmiceli          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "get_next_line.h"
#include <limits.h>
#include <fcntl.h>
#include <stdio.h>
#define TEST ft_putendl_color("TEST", "cyan");

static int		ft_buff_check(char *buff, t_param *param)
{
	param->i = 0;
	while (param->i < BUFF_SIZE)
	{
		if (param->i + 1 < BUFF_SIZE && buff[param->i + 1] == EOF)
			return (2);
		if (buff[param->i] == '\n')
			return (1);
		param->i++;
	}
	return (0);
}

static char		*ft_before_after(char *buff, t_param *param, char *line)
{
	int		i;
	int		j;
	char	*before;

	j = 0;
	if (buff[BUFF_SIZE - 1] == '\n')
		return (ft_strjoin_free(line, buff));
	if (!(before = (char *)malloc(sizeof(char) * param->i + 1)))
		return (NULL);
	if (!(param->after = (char *)malloc(sizeof(char) *
					(BUFF_SIZE - param->i - 1))))
		return (NULL);
	i = 0;
	while (buff[i] != '\n' && i < BUFF_SIZE)
	{
		before[i] = buff[i];
		i++;
	}
	before[i] = '\0';
	i++;
	while (i < BUFF_SIZE)
		param->after[j++] = buff[i++];
	return (ft_strjoin_free(line, before));
}

int				get_next_line(const int fd, char **line)
{
	int					ret;
	char				buff[BUFF_SIZE];
	static t_param		param;

	if ((!param.after && !(param.after = (char *)ft_memalloc(sizeof(char) * 1)))
			|| (!(fd)))
		return (-1);
	*line = ft_strjoin("\0", param.after);
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		if (ft_buff_check(buff, &param) == 1) //renvoie toujours 1 = pas normal//
		{
			*line = ft_before_after(buff, &param, *line);
			return (1);
		}
		else if (ft_buff_check(buff, &param) == 2)// ne rentre jamais dedant //
		{
			TEST;
			ft_strjoin_free(*line, buff);
			return (0);
		}
		else
			*line = ft_strjoin_free(*line, buff);
	}
	return (0);
}