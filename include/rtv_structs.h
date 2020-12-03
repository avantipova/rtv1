
#ifndef RTV_STRUCTS_H
# define RTV_STRUCTS_H


# include "SDL.h"
# include "../libft/include/libft.h"
# include "vector.h"
# define EPS 0.000001
# define VECTOR_W 40
# define VECTOR_H 40

typedef enum		e_obj_types
{
	SPHERE,
	PLANE,
	CONE,
	CYLINDER,
	DIRECT_LIGHT,
}					t_obj_types;

typedef struct 		s_color
{
	uint8_t			red;
	uint8_t			green;
	uint8_t			blue;
}					t_color;

typedef struct		s_object
{
	t_obj_types		type;
	t_vector		pos;
	t_vector		dir;
	t_vector		rot;
	t_color			color;
	double 			size;
	double			angle;
	double			r;
	double			t;
	double 			specular;
}					t_object;

typedef	struct		s_ray
{
	t_vector		orig;
	t_vector		dir;
}					t_ray;

typedef struct		s_camera
{
	t_vector		pos;
	t_vector		rot;
}					t_camera;

typedef	struct		s_light
{
	t_vector		pos;
	t_vector		p;
	t_vector		n;
	double			inten;
	double			new_inten;
}					t_light;

typedef struct		s_scene
{
	t_list			objects;
	t_list			lights;
	t_camera		cam;
	const char 		*fname;
	double			ambient;
	int				cams;
}					t_scene;

typedef struct		s_rtv
{
	SDL_Window		*window;
	SDL_Renderer	*rend;
	const char		*wname;
	t_scene			*scene;
	int				height;
	int 			width;
	int				clos_obj;
	double			min_t;
	t_light			*light;
}					t_rtv;
#endif
