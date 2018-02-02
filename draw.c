/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 16:58:12 by alamy             #+#    #+#             */
/*   Updated: 2018/02/02 12:51:26 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "stdio.h"
#include "fdf.h"

void ft_draw_line_horiz(t_env *tmp)
{
	int i;
	int j;
	int x;
	int y;
	int x1;
	int y1;

	i = 0;
	while (i < tmp->nb_line)
	{
		j = 0;
		while (j < tmp->map->lines[i]->lenght - 1)
		{
			x = tmp->map->lines[i]->points[j]->x;
			y = tmp->map->lines[i]->points[j]->y;
			x1 = tmp->map->lines[i]->points[j + 1]->x;
			y1 = tmp->map->lines[i]->points[j + 1]->y;
			ft_bresenham(x, y, x1, y1, tmp);
			j++;
		}
		i++;
	}
}

void ft_draw_line_vertical(t_env *tmp)
{
	int i;
	int j;
	int x;
	int y;
	int x1;
	int y1;
	
	i = 0;
	j = 0;
	while (j < tmp->map->lines[i]->lenght)
	{
		while (i < tmp->nb_line - 1)
		{
			x = tmp->map->lines[i]->points[j]->x;
			y = tmp->map->lines[i]->points[j]->y;
			x1 = tmp->map->lines[i + 1]->points[j]->x;
			y1 = tmp->map->lines[i + 1]->points[j]->y;
			ft_putnbr(x);
			ft_putchar(' ');
			ft_putnbr(y);
			ft_putchar(' ');
			ft_putnbr(x1);
			ft_putchar(' ');
			ft_putnbr(y1);
			ft_putchar('\n');
			ft_bresenham(x, y, x1, y1, tmp);
			i++;
		}
		i = 0;
		j++;
	}
}
