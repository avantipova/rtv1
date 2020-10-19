#include "vector.h"
#include <math.h>

t_double2		sphere_intersection(t_vector *st, t_vector *dir, t_vector *cent, double r)
{
	double 		a;
	double 		b;
	double 		c;
	t_double2	res;
	t_vector	tmp;

	a = ft_vecdot(*dir, *dir);
	tmp = ft_vecsub(*st, *cent);
	b = ft_vecdot(*dir, tmp);
	c = ft_vecdot(tmp, tmp) - r * r;
	c = b * b - a * c;
	res.a = NAN;
	res.b = NAN;
	if (c >= 0)
	{
		c = sqrt(c) / a;
		res.a = -b / a + c;
		res.b = -b / a - c;
	}
	return (res);
}
