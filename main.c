/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/05 14:09:40 by alamy             #+#    #+#             */
/*   Updated: 2018/02/02 17:49:46 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int argc, char **argv)
{
	t_env tmp;

	if (argc != 2)
		ft_putstr("too many or too few arguments\n");
	tmp.nb_line = ft_nb_line(argv); 
	tmp.nb_col = ft_nb_col(argv);
	ft_putnbr(tmp.nb_col);
	tmp.mlx = mlx_init();
	tmp.win = mlx_new_window(tmp.mlx, WINDOW_L, WINDOW_H, "mlx 42");
	tmp.map = ft_begin_parse(argv);
	ft_create_image(&tmp);
	mlx_key_hook(tmp.win, my_key_funct, &tmp);
	// mlx_mouse_hook(tmp.win, my_mouse_funct, &tmp);
	mlx_loop(tmp.mlx);
	return (0);
}
