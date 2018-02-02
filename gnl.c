/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/09 16:31:22 by cmace             #+#    #+#             */
/*   Updated: 2018/02/02 18:32:01 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static char		*ft_dl_aft_nl(char *tmp)
{
	int	i;

	i = 0;
	while (tmp[i] != '\n' && tmp[i] != '\0')
		i++;
	while (tmp[i] != '\0')
	{
		tmp[i] = '\0';
		i++;
	}
	return (tmp);
}

static char		*ft_strjoinfree(char *tmp, char *buf)
{
	char	*str;

	str = ft_strjoin(tmp, buf);
	free(tmp);
	return (str);
}

static int		ft_whallbeokay(char **save, char *buf, char **tmp, char **line)
{
	int		i;

	i = -1;
	*tmp = ft_strjoinfree(*tmp, buf);
	while (buf[++i] != '\0')
		if (buf[i] == '\n')
		{
			*save = ft_strdup(buf + i + 1);
			*line = ft_strdup(ft_dl_aft_nl(*tmp));
			free(*tmp);
			return (1);
		}
	return (0);
}

static int		ft_whenbuf_is_sooo_large(char **save, t_val *value, char **line)
{
	value->i = -1;
	while (value->tmp[++(value->i)])
		if (value->tmp[value->i] == '\n')
		{
			*save = ft_strdup(*save + value->i + 1);
			*line = ft_strdup(ft_dl_aft_nl(value->tmp));
			free(value->tmp);
			return (1);
		}
	return (0);
}

int				gnl(const int fd, char **line)
{
	t_val		value;
	static char *save = NULL;
	char		buf[BUFF_SIZE + 1];

	if (fd <= -1 || !(line))
		return (-1);
	value.tmp = ft_memalloc(1);
	(save != NULL) ? value.tmp = ft_strdup(save) : NULL;
	if (ft_whenbuf_is_sooo_large(&save, &value, line))
		return (1);
	while (1)
	{
		if ((value.ret = read(fd, buf, BUFF_SIZE)) < 0)
			return (-1);
		else if (value.ret == 0)
		{
			save = NULL;
			*line = ft_strdup(ft_dl_aft_nl(value.tmp));
			ft_strdel(&value.tmp);
			return ((*line)[0] != '\0');
		}
		buf[value.ret] = '\0';
		if (ft_whallbeokay(&save, buf, &value.tmp, &(*line)) == 1)
			return (1);
	}
}