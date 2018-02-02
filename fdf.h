/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 11:49:43 by alamy             #+#    #+#             */
/*   Updated: 2018/02/02 18:31:57 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# define BUFF_SIZE 32
# define WINDOW_L 2000
# define WINDOW_H 1300
# define TILE_WIDTH 25
# define TILE_HEIGHT 25
# define PI 3.14159265359

# include "minilibx/mlx.h"
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include "libft/libft.h"

/*DEFINE EVENTS KEY FUNCT*/
# define RIGHT 124
# define LEFT 123
# define UP 126
# define DOWN 125
# define ROTATION_X_UP 91
# define ROTATION_X_DOWN 84
# define ROTATION_Z_RIGHT 88
# define ROTATION_Z_LEFT 86
# define ROTATION_Y_A 0
# define ROTATION_Y_W 13
# define EXIT 53

/*DEFINE EVENTS MOUSE FUNCT*/
# define SCROLL_UP 4
# define SCROLL_DOWN 5
# define CLIC_RIGHT 2
# define CLIC_LEFT 1
# define CLIC_MIDDLE 3

typedef struct s_points
{
	int x;
	int y; 
	int z;
	int w;
	char *color;
}				t_points;

typedef struct s_lines
{
	t_points **points;
	int lenght;
}				t_lines;

typedef struct	s_map
{
	t_lines **lines;
	// int nb_line;
}				t_map;

//GNL
typedef struct	s_val
{
	int			i;
	int			ret;
	char		*tmp;
}				t_val;

typedef struct	s_algob
{
	int ex;
	int ey;
	int dx;
	int dy;
	int Dx;
	int Dy;
	int i;
	int Xincr;
	int Yincr;
}				t_algob;

typedef struct	s_img
{
	void 	*img_ptr;
	int 	*data;
	int 	bpp;
	int 	size_bits;
	int 	endian;
	unsigned int color;
}				t_img;

typedef struct	s_env
{
	void *mlx;
	void *win;
	t_img img;
	t_map *map;
	int new_move_y;
	int new_move_x;
	int nb_line;
	int nb_col;
}				t_env;

// GNL
int				gnl(const int fd, char **line);

/*PARSING*/
int main(int argc, char **argv);
int ft_nb_line(char **argv);
int	ft_getnbr(char *str);
int ft_lenght(char **str);
int ft_nb_col(char **argv);
void ft_print_tab(t_env *tmp);
t_map *ft_begin_parse(char **argv);
t_points **ft_stock_points(char *line, int index, t_points ***points, t_lines *elts);

/*IMAGE*/
void ft_create_image(t_env *tmp);
void ft_create_new_image(t_env *tmp);
void fill_pixel(t_env *tmp, int x, int y, int color);

/*BRESENHAM*/
void ft_transform_map(t_env *tmp);
void ft_draw_line_horiz(t_env *tmp);
void ft_draw_line_vertical(t_env *tmp);
void print_horiz_line(t_env *tmp, int i, int j);
void print_vertical_line(t_env *tmp, int i, int j);
void ft_bresenham(int x0, int y0, int x1, int y1, t_env *tmp);
// void ft_bresenham1(t_algob *b, t_env *tmp, int x0, int y0);
// void ft_bresenham2(t_algob *b, t_env *tmp, int x0, int y0);
void ft_bre_1(t_algob *b, t_env *tmp, int x0, int y0);
void ft_bre_2(t_algob *b, t_env *tmp, int x0, int y0);

/*EVENT*/
int my_key_funct(int keycode, t_env *tmp);
int my_mouse_funct(int keycode, t_env *tmp);


/*MATRIX*/
typedef struct s_vecteur4
{
	float x1;
	float y1;
	float z1;
	float w1;
}				t_vecteur4;

typedef struct s_matrix t_matrix;
typedef union 
{
	float m[4][4];
    struct	s_matrix
    {
		float a1;
		float a2; 
		float a3;
		float a4;
		float b1;
		float b2; 
		float b3; 
		float b4;
		float c1;
		float c2;
		float c3;
		float c4;
		float d1;
		float d2;
		float d3;
		float d4;
	}	   	t_matrix;
} matrix4_t;

matrix4_t  matrix4(t_matrix m);
matrix4_t  matrix_identity(void);
matrix4_t  matrix_translation_center(t_vecteur4 vecteur);
matrix4_t  matrix_homothetie(t_vecteur4 homo);
matrix4_t  matrix_rotationX(float alpha);
matrix4_t  matrix_rotationY(float alpha);
matrix4_t  matrix_rotationZ(float alpha);
matrix4_t  matrix_projection(float angle, float ratio, float near, float far); 
t_vecteur4 create_vecteur4(int x, int y, int z, int w);
t_vecteur4 ft_transformation(int x, int y, int z, int w, int i, t_env *tmp);
t_vecteur4 ft_cal_translation(t_vecteur4 vecteur2, matrix4_t matrix_translation);
t_vecteur4 ft_cal_rotationX(t_vecteur4 vecteur, matrix4_t matrix_rotationX);
t_vecteur4 ft_cal_rotationY(t_vecteur4 vecteur, matrix4_t matrix_rotationY);
t_vecteur4 ft_cal_rotationZ(t_vecteur4 vecteur, matrix4_t matrix_rotationZ);
t_vecteur4 ft_cal_homothetie(t_vecteur4 vecteur, matrix4_t matrix_homothetie);
t_vecteur4 ft_cal_projection(t_vecteur4 vecteur, matrix4_t matrix_homothetie);
void ft_print_matrix(matrix4_t matrix);

/*NEW_EVENTS_TRANSFORMATION*/
void ft_transformation_event(t_env *tmp, int keycode);
t_vecteur4 ft_rotationx1(int x, int y, int z, int w, int i);
t_vecteur4 ft_rotationx2(int x, int y, int z, int w, int i);
t_vecteur4 ft_rotationz1(int x, int y, int z, int w, int i);
t_vecteur4 ft_rotationz2(int x, int y, int z, int w, int i);
t_vecteur4 ft_homothetie_event(int x, int y, int z, int w, int i);

#endif
