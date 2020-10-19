
#ifndef RTV_STRUCTS_H
# define RTV_STRUCTS_H


# include "SDL.h"
# include "../libft/include/libft.h"
# include "vector.h"

typedef enum		e_obj_types
{
	SPHERE,
	INV_SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	DIRECT_LIGHT,
	INDIRECT_LIGHT
}					t_obj_types;

typedef struct		s_arguments
{
	const char		*fname;
	int 			w_height;
	int 			w_width;
}					t_arguments;

typedef struct 		s_color
{
	uint8_t			red;
	uint8_t			green;
	uint8_t			blue;
	uint8_t			alpha;
}					t_color;

typedef struct		s_object
{
	t_obj_types		type;
	t_vector		position;
	t_vector		direction;
	t_color			color;
	double 			size;
	double			angle;
}					t_object;

typedef struct 		s_intersec
{
	t_object		*obj;
	t_vector		ray;
	double 			rlen;
	t_vector		start;
}					t_intersec;

typedef struct		s_camera
{
	t_vector		origin;
	t_vector		direction;
	t_vector		center;
	t_vector		up;
	t_vector		right;
	t_vector		forward;
	int 			height;
	int				width;
}					t_camera;

typedef struct		s_scene
{
	t_list			objects;
	t_list			lights;
	t_camera		cam;
}					t_scene;

typedef struct		s_rtv
{
	SDL_Window		*window;
	SDL_Renderer	*rend;
	t_scene			*scene;
	const char		*wname;
	int				height;
	int 			width;
}					t_rtv;

#endif
