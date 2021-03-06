/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldeirdre <ldeirdre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/04 15:55:57 by ldeirdre          #+#    #+#             */
/*   Updated: 2020/12/04 15:56:28 by ldeirdre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_MATH_VECTOR_H
# define VECTOR_MATH_VECTOR_H

# include <math.h>
# include <float.h>
# include <fcntl.h>
# define DTR(a)	((double)a * (M_PI / 180))

typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
}				t_vector;

typedef struct	s_double2
{
	double		a;
	double		b;
}				t_double2;

t_vector		ft_vecsub(t_vector v1, t_vector v2);
t_vector		ft_vecsum(t_vector v1, t_vector v2);
double			ft_vecdot(t_vector v1, t_vector v2);
double			ft_veclen(t_vector v);
t_vector		ft_vecscale(t_vector v, double scale);
t_vector		ft_vecnorm(t_vector v);
t_vector		ft_vecrot(t_vector d, t_vector r);
t_vector		ft_vecrotx(t_vector d, double a);
t_vector		ft_vecroty(t_vector d, double a);
t_vector		ft_vecrotz(t_vector d, double a);
#endif
