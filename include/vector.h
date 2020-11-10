#ifndef VECTOR_MATH_VECTOR_H
#define VECTOR_MATH_VECTOR_H

#include <math.h>
#include <float.h>
# include <fcntl.h>

typedef struct	s_vector
{
	double 		x;
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
t_double2		sphere_intersection(t_vector *st, t_vector *dir, t_vector *cent, double r);
t_vector		vecsphere_intersection(t_vector st, t_vector dir, t_vector cent, double r);
t_double2		plane_intersection(t_vector *st, t_vector *dir, t_vector *or, t_vector *norm);
t_double2		cylinder_intersection(t_vector *st, t_vector *dir, t_vector *cent, t_vector *dire,  double r);
t_double2		cone_intersection(t_vector *st, t_vector *dir, t_vector *dire, t_vector *cent, double angle, double r);
t_vector		ft_vecrot(t_vector d, t_vector r);
t_vector		ft_vecrotx(t_vector d, double a);
t_vector		ft_vecroty(t_vector d, double a);
t_vector		ft_vecrotz(t_vector d, double a);
#endif 