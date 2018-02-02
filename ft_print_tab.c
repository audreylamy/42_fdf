/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_tab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/10 17:18:55 by alamy             #+#    #+#             */
/*   Updated: 2018/02/02 12:40:57 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void    ft_print_tab(t_env *tmp)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < tmp->nb_line)
	{
        j = 0;
		while (j < tmp->map->lines[i]->lenght)
		{
            ft_putnbr(tmp->map->lines[i]->points[j]->x);
            ft_putnbr(tmp->map->lines[i]->points[j]->y);
            ft_putnbr(tmp->map->lines[i]->points[j]->z);
            ft_putnbr(tmp->map->lines[i]->points[j]->w);
            ft_putstr(tmp->map->lines[i]->points[j]->color);
            ft_putchar('\n');
            j++;
        }
        i++;
    }
}