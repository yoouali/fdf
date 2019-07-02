#include "mlx.h"

void drawline(int x0, int y0, int x1, int y1, void *ptr, void *win)
{
	int dx, dy, p, x, y;

	dx=x1-x0;
	dy=y1-y0;

	x=x0;
	y=y0;

	p=2*dy-dx;

	while(x<x1)
	{
		if(p>=0)
		{
			mlx_pixel_put(ptr,win,x,y,0xff);
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			mlx_pixel_put(ptr,win,x,y,0xff);
			p=p+2*dy;
		}
		x=x+1;
	}
}

int main()
{

	void *ptr = mlx_init();
	void *win = mlx_new_window(ptr, 500, 500, "fdftest");
	mlx_pixel_put(ptr, win, 150, 150, 0xfffff);
	mlx_pixel_put(ptr, win, 250, 250, 0xfffff);
	drawline(150, 150, 250,250, ptr, win);
	mlx_loop(ptr);
}
