#include "vector.h"
#include <math.h>

t_double2		cone_intersection(t_vector *st, t_vector *dir, t_vector *dire, t_vector *cent, double angle, double r)
{
	t_vector 	tmp;
	double		tang;
	double		x;
	double		y;
	double 		a;
	double		b;
	double		c;
	t_double2	res;


	tang = tan(angle * M_PI / 180);
	tmp = ft_vecsub(*st, *cent);
	x = ft_vecdot(*dir, *dire);
	y = ft_vecdot(tmp, *dire);
	a = ft_vecdot(*dir, *dir) - ((1 + pow(tang, 2)) * pow(x, 2));
	b = 2 * (ft_vecdot(*dir, tmp) - ((1 + pow(tang, 2)) * x * y));
	c = ft_vecdot(tmp, tmp) - (1 + pow(tang, 2) * pow(y, 2));
	c = b * b -  4 * a * c;
	res.a = NAN;
	res.b = NAN;
	if (c >= 0)
	{
		res.a = (-b + sqrtf(c)) / (2 * a);
		res.b = (-b - sqrtf(c)) / (2 * a);
	}
	return (res);
}

/*t_double2		cone_intersection(t_vector *st, t_vector *dir, t_vector *dire, t_vector *cent, double angle, double r)/*
{
	t_vector 	tmp;
	double		tang;
	double		x;
	double		y;
	double 		a;
	double		b;
	double		c;
	double d;
	t_double2	res;

	tmp = ft_vecsub(*st, *cent);
	a = ft_vecdot(*dir, *dire);
	a = ft_vecdot(*dir, *dir) - (1 + r * r) * a * a;
	b = 2.0 * (ft_vecdot(*dir, tmp) - (1 + r * r) * ft_vecdot(*dir, *dire) * ft_vecdot(tmp, *dire));
	c = ft_vecdot(tmp, *dire);
	c = ft_vecdot(tmp, tmp) - (1 + r * r) * c * c;
	d = b * b -  4 * a * c;
	res.a = NAN;
	res.b = NAN;
	if (c >= 0)
	{
		res.a = (-b + sqrtf(d)) / (2 * a);
		res.b = (-b - sqrtf(d)) / (2 * a);
	}
	return (res);
}*/