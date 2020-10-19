#include "vector.h"
#include <math.h>

t_double2		cylinder_intersection(t_vector *st, t_vector *dir, t_vector *cent, t_vector *dire,  double r)
{
	t_vector 	tmp;
	double 		a;
	double 		b;
	double 		c;
	double		x;
	double		y;
	t_double2	res;

	tmp = ft_vecsub(*st, *cent);
	x = ft_vecdot(*dir, *dire);
	y = ft_vecdot(tmp, *dire);
	a = ft_vecdot(*dir, *dir);
	a = ft_vecdot(*dir, *dir) - pow(x, 2);
	b = 2 * (ft_vecdot(*dir, tmp) - (x * y));
	c = ft_vecdot(tmp, tmp) - pow(y, 2) - pow(r, 2);
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