#include "vector.h"
#include <math.h>
#include <float.h>
#include "stdio.h"

t_double2		plane_intersection(t_vector *st, t_vector *dir, t_vector *or, t_vector *norm)
{
	double up;
	double down;

	up = ft_vecdot(ft_vecsub(*or, *st), *norm);
	down = ft_vecdot(*dir, *norm);
	if (fabs(down) < DBL_MIN)
		return ((t_double2){NAN, NAN});
	else
		return ((t_double2){up / down, up / down});
}
