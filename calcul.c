/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calcul.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 09:31:57 by alamy             #+#    #+#             */
/*   Updated: 2018/02/02 11:51:30 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int ft_nb_line(char **argv)
{
	int		index;
	int 	nb_line;
	int		fd;
	char	*line;

	fd = open(argv[1], O_RDONLY);
	nb_line = 0;
	index = 0;
	while (get_next_line(fd, &line) > 0)
	{
		nb_line++;
	}
	return(nb_line);
}

int ft_lenght(char **str)
{
	int y;

	y = 0;
	while(str[y] != '\0')
	{
		y++;
	}
	return(y);
}

int	ft_getnbr(char *str)
{
	size_t	i;
	int		result;

	result = 0;
	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		result = (result * 10) + (str[i] - '0');
		i++;
	}
	if (str[0] == '-')
		result = result * (-1);
	return (result);
}
