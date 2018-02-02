/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Deydou <Deydou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/20 16:48:13 by alamy             #+#    #+#             */
/*   Updated: 2018/01/23 22:16:46 by Deydou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void ft_print_matrix(matrix4_t matrix)
{
	int i;
	int j;

	i = 0;
	while(i < 4)
	{
		j = 0;
		while(j < 4)
		{
			ft_putnbr(matrix.m[i][j]);
			if (j == 3)
				ft_putchar('\n');
			j++;
		}
		i++;
	}
}
