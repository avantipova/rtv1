
#include "app_funcs.h"

void	run_app(t_rtv *rtv)
{
	int				status;
	SDL_Event		e;

	status = 1;
	SDL_SetRenderDrawColor(rtv->rend, 0, 0, 0, 0xFF);
	SDL_RenderClear(rtv->rend);
	render_scene(rtv->rend, rtv->scene);
	SDL_RenderPresent(rtv->rend);
	while (status)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				status = 0;
		}
	}
}
