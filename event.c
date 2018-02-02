/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 10:39:04 by alamy             #+#    #+#             */
/*   Updated: 2018/02/02 16:01:18 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void ft_create_new_image(t_env *tmp)
{
	mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
	tmp->img.img_ptr = mlx_new_image(tmp->mlx, WINDOW_L, WINDOW_H);
	tmp->img.data = (int*)mlx_get_data_addr(tmp->img.img_ptr, &tmp->img.bpp, &tmp->img.size_bits, &tmp->img.endian);
	ft_draw_line_horiz(tmp);
	ft_draw_line_vertical(tmp);
 	mlx_put_image_to_window(tmp->mlx, tmp->win, tmp->img.img_ptr, 0, 0);
}

int my_key_funct(int keycode, t_env *tmp)
{
	printf("key event %d\n", keycode);
	if (keycode == 53)
	{
		mlx_destroy_image(tmp->mlx, tmp->img.img_ptr);
		exit(0);
	}
	if (keycode == UP)
	{	
		tmp->new_move_y -= 20;
		ft_print_tab(tmp);
		ft_create_new_image(tmp);
	}
	if (keycode == RIGHT)
	{	
		tmp->new_move_x += 20;
		ft_create_new_image(tmp);
	}
	if (keycode == DOWN)
	{	
		tmp->new_move_y += 20;
		ft_create_new_image(tmp);
	}
	if (keycode == LEFT)
	{	
		tmp->new_move_x -= 20;
		ft_create_new_image(tmp);
	}
	if (keycode == ROTATION_X_DOWN) // 2
	{	
		ft_transformation_event(tmp, keycode);
		ft_create_new_image(tmp);
	}
	if (keycode == ROTATION_X_UP) // 8
	{	
		ft_transformation_event(tmp, keycode);
		ft_create_new_image(tmp);
	}
	if (keycode == ROTATION_Z_RIGHT) // 6
	{	
		ft_transformation_event(tmp, keycode);
		ft_create_new_image(tmp);
	}
	if (keycode == ROTATION_Z_LEFT) // 4
	{	
		ft_transformation_event(tmp, keycode);
		ft_create_new_image(tmp);
	}
	if (keycode == ROTATION_Y_A) // 0
	{	
		ft_transformation_event(tmp, keycode);
		ft_create_new_image(tmp);
	}
	if (keycode == ROTATION_Y_W) // 13
	{	
		ft_transformation_event(tmp, keycode);
		ft_create_new_image(tmp);
	}
	return(0);
}

// int my_mouse_funct(int keycode, t_env *tmp)
// {
// 	printf("key event %d\n", keycode);
// 	if (keycode == CLIC_LEFT)
// 	{	
// 		ft_transformation_event(tmp);
// 		ft_create_new_image(tmp);
// 	}
// 	return(0);
// }

t_vecteur4 ft_rotationx1(int x, int y, int z, int w, int i)
{
	t_vecteur4 	vecteur_rotation_x;
	matrix4_t 	m_rotation_x;
	t_vecteur4 resultat;
	
	m_rotation_x = matrix_rotationX((10 * PI) / 180);
	resultat = create_vecteur4(x, y, z, w);
	resultat = ft_cal_rotationX(resultat, m_rotation_x);
	return(resultat);
}

t_vecteur4 ft_rotationx2(int x, int y, int z, int w, int i)
{
	t_vecteur4 	vecteur_rotation_x;
	matrix4_t 	m_rotation_x;
	t_vecteur4 resultat;
	
	m_rotation_x = matrix_rotationX((-10 * PI) / 180);
	resultat = create_vecteur4(x, y, z, w);
	resultat = ft_cal_rotationX(resultat, m_rotation_x);
	return(resultat);
}

t_vecteur4 ft_rotationz1(int x, int y, int z, int w, int i)
{
	t_vecteur4 	vecteur_rotation_z;
	matrix4_t 	m_rotation_z;
	t_vecteur4 resultat;
	
	m_rotation_z = matrix_rotationZ((1.0 * PI) / 180);
	resultat = create_vecteur4(x, y, z, w);
	resultat = ft_cal_rotationZ(resultat, m_rotation_z);
	return(resultat);
}

t_vecteur4 ft_rotationz2(int x, int y, int z, int w, int i)
{
	t_vecteur4 	vecteur_rotation_z;
	matrix4_t 	m_rotation_z;
	t_vecteur4 resultat;
	
	m_rotation_z = matrix_rotationZ((-1.0 * PI) / 180);
	resultat = create_vecteur4(x, y, z, w);
	resultat = ft_cal_rotationZ(resultat, m_rotation_z);
	return(resultat);
}

t_vecteur4 ft_rotationy1(int x, int y, int z, int w, int i)
{
	t_vecteur4 	vecteur_rotation_y;
	matrix4_t 	m_rotation_y;
	t_vecteur4 resultat;
	
	m_rotation_y = matrix_rotationY((10.0 * PI) / 180);
	resultat = create_vecteur4(x, y, z, w);
	resultat = ft_cal_rotationY(resultat, m_rotation_y);
	return(resultat);
}

t_vecteur4 ft_rotationy2(int x, int y, int z, int w, int i)
{
	t_vecteur4 	vecteur_rotation_y;
	matrix4_t 	m_rotation_y;
	t_vecteur4 resultat;
	
	m_rotation_y = matrix_rotationY((-10.0 * PI) / 180);
	resultat = create_vecteur4(x, y, z, w);
	resultat = ft_cal_rotationY(resultat, m_rotation_y);
	return(resultat);
}

// t_vecteur4 ft_homothetie_event(int x, int y, int z, int w, int i)
// {
// 	t_vecteur4 	vecteur_homothetie;
// 	matrix4_t 	m_homothetie;
// 	t_vecteur4 resultat;
	
// 	vecteur_homothetie = create_vecteur4(2, 1, 1, 1);
// 	m_homothetie = matrix_homothetie(vecteur_homothetie);

// 	resultat = create_vecteur4(x, y, z, w);

// 	resultat = ft_cal_homothetie(resultat, m_homothetie);
// 	return(resultat);
// }

void ft_transformation_event(t_env *tmp, int keycode)
{
	int i;
	int j;
	int x0;
	int y0;
	int z0;
	int w0;
	t_vecteur4 	resultat;

	i = 0;
	while (i < tmp->nb_line)
	{
		j = 0;
		while (j < tmp->map->lines[i]->lenght)
		{
			x0 = tmp->map->lines[i]->points[j]->x;
			y0 = tmp->map->lines[i]->points[j]->y;
			z0 = tmp->map->lines[i]->points[j]->z;
			w0 = tmp->map->lines[i]->points[j]->w;
			if (keycode == 84)
				resultat = ft_rotationx1(x0, y0, z0, w0, i);
			else if (keycode == 91)
				resultat = ft_rotationx2(x0, y0, z0, w0, i);
			else if (keycode == 88)
				resultat = ft_rotationz1(x0, y0, z0, w0, i);
			else if (keycode == 86)
				resultat = ft_rotationz2(x0, y0, z0, w0, i);
			else if (keycode == 0)
				resultat = ft_rotationy1(x0, y0, z0, w0, i);
			else if (keycode == 13)
				resultat = ft_rotationy2(x0, y0, z0, w0, i);
			tmp->map->lines[i]->points[j]->x = resultat.x1;
			tmp->map->lines[i]->points[j]->y = resultat.y1;
			tmp->map->lines[i]->points[j]->z = resultat.z1;
			tmp->map->lines[i]->points[j]->w = resultat.w1;
			j++;
		}
		i++;
	}
}

