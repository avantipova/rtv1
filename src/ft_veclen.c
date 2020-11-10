#include "vector.h"

inline double	ft_veclen(t_vector v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}