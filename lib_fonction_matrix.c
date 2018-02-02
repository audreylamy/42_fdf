/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_fonction_matrix.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamy <alamy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/19 13:47:27 by alamy             #+#    #+#             */
/*   Updated: 2018/02/02 10:55:45 by alamy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

matrix4_t  matrix4(t_matrix m) 
{
    return (matrix4_t)
    {
        {{m.a1, m.a2, m.a3, m.a4},
         {m.b1, m.b2, m.b3, m.b4},
         {m.c1, m.c2, m.c3, m.c4},
         {m.d1, m.d2, m.d3, m.d4}}
    };
}

matrix4_t  matrix_identity(void)
{
    return matrix4((t_matrix)
		{1, 0, 0, 0,
		 0, 1, 0, 0,
		 0, 0, 1, 0,
		 0, 0, 0, 1}
    );
}

/*MATRICE TRANSLATION*/

matrix4_t  matrix_translation_center(t_vecteur4 offset)
{
    return matrix4((t_matrix)
		{1, 0, 0, offset.x1,
		 0, 1, 0, offset.y1,
		 0, 0, 1, offset.z1,
		 0, 0, 0, offset.w1}
    );
}

/*MATRICE ROTATION*/

matrix4_t  matrix_rotationX(float angle)
{
    return matrix4((t_matrix)
		{1, 0, 0, 0,
		 0, cos(angle), -sin(angle), 0,
		 0, sin(angle), cos(angle), 0,
		 0, 0, 0, 1}
    );
}

matrix4_t  matrix_rotationY(float angle)
{
    return matrix4((t_matrix)
		{cos(angle), 0, sin(angle), 0,
		 0, 1, 0, 0,
		 -sin(angle), 0, cos(angle), 0,
		 0, 0, 0, 1}
    );
}

matrix4_t  matrix_rotationZ(float angle)
{
    return matrix4((t_matrix)
		{cos(angle), -sin(angle), 0, 0,
		 sin(angle), cos(angle), 0, 0,
		 0, 0, 1, 0,
		 0, 0, 0, 1}
    );
}

/*MATRICE HOMOTHETIE*/

matrix4_t  matrix_homothetie(t_vecteur4 homo)
{
    return matrix4((t_matrix)
		{homo.x1, 0, 0, 0,
		 0, homo.y1, 0, 0,
		 0, 0, homo.z1, 0,
		 0, 0, 0, homo.w1}
    );
}

/*MATRICE PROJECTION*/

matrix4_t matrix_projection(float angle, float ratio, float near, float far) 
{
	float f;
	float r;
	float nd;
	float fd;

	f = 1 / tan(angle / 2);
	r = ratio;
	nd = near;
	fd = far;
	
	return matrix4((t_matrix)
		 {f / r,          0,                0,                0,
		 0,                f,                0,                0,
		 0,                0,               (-fd-nd)/(nd-fd),  (2*fd*nd)/(nd-fd),
		 0,                0,                1,                0}
	);
}

t_vecteur4 create_vecteur4(int x, int y, int z, int w)
{
	t_vecteur4 new_vecteur4;

	new_vecteur4.x1= x;
	new_vecteur4.y1= y;
	new_vecteur4.z1= z;
	new_vecteur4.w1= w;
	return(new_vecteur4);
}
