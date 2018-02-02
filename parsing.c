/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:19:16 by alamy             #+#    #+#             */
/*   Updated: 2018/02/02 18:33:43 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map *ft_begin_parse(char **argv)
{	
	char *line;
	int fd;
	t_map *map;
	t_lines *elts;
	t_points **position;
	int index;
	
	index = 0;
	if (!(map = (t_map*)malloc(sizeof(t_map))))
		exit(0);
	if (!(map->lines = (t_lines**)malloc(sizeof(t_lines) * ft_nb_line(argv))))
		exit(1);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_putstr("open() failed\n");
	while (gnl(fd, &line) > 0)
	{	
		if ((elts = (t_lines*)malloc(sizeof(t_lines))) == NULL)
			exit(0);
		elts->points = ft_stock_points(line, index, &position, elts);
		map->lines[index] = elts;
		index++;
	}
	free(line);
	if (close(fd) == -1)
	{
		ft_putstr("close() failed\n");
	}
	return(map);
}

t_points **ft_stock_points(char *line, int index, t_points ***points, t_lines *elts)
{
	int			i;
    int         z;
	int			a;
	char		**str;
	t_points 	*a_points;
    
	i = 0;
    z = 0;
	a = 0;
	str = ft_strsplit(line, ' ');
	elts->lenght = ft_lenght(str);
	if (((*points) = (t_points**)malloc(sizeof(t_points) * elts->lenght)) == NULL)
		exit(1);
    while (str[i] != '\0')
    {
		if ((a_points = (t_points*)malloc(sizeof(t_points))) == NULL)
			exit(1);
		a_points->x = i * TILE_WIDTH;
        a_points->y = index * TILE_HEIGHT;
		a_points->w = 1;
		if (ft_strchr(str[i], ',')) 
		{
			a_points->z = ft_getnbr(str[i]);
			a = 0;
			while (str[i][a] != '\0')
			{
				if (str[i][a] == ',')
				{
					a_points->color = &str[i][a + 1];
				}
				a++;
			}
		}
	    else
		{
			a_points->color = "0xFFFFFF";    
			a_points->z = ft_getnbr(str[i]);
		}
		(*points)[i] = a_points;
		i++;
    }
	return(*points);
}
