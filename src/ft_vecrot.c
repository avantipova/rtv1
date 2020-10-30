#include "vector.h"
# include <fcntl.h>
# include <math.h>

# define DTR(a)	((double)a * (M_PI / 180))

t_vector	ft_vecrot(t_vector d, t_vector r)
{
	d = ft_vecrotx(d, DTR(r.x));
	d = ft_vecroty(d, DTR(r.y));
	d = ft_vecrotz(d, DTR(r.z));
	return (d);
}

t_vector	ft_vecrotx(t_vector d, double a)
{
	t_vector r;

	r.x = d.x;
	r.y = d.y * cos(a) - d.z * sin(a);
	r.z = d.y * sin(a) + d.z * cos(a);
	return (r);
}

t_vector	ft_vecroty(t_vector d, double a)
{
	t_vector r;

	r.x = d.x * cos(a) + d.z * sin(a);
	r.y = d.y;
	r.z = d.z * cos(a) - d.x * sin(a);
	return (r);
}

t_vector	ft_vecrotz(t_vector d, double a)
{
	t_vector	r;

	r.x = d.x * cos(a) - d.y * sin(a);
	r.y = d.x * sin(a) + d.y * cos(a);
	r.z = d.z;
	return (r);
}
