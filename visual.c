#include "fractol.h"

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void draw_line(void *mlx, void *win, int beginX, int beginY, int endX, int endY, int color) //
{
	double deltaX = endX - beginX; // 10
	double deltaY = endY - beginY; // 0
	int pixels = sqrt((deltaX * deltaX) + (deltaY * deltaY));
	int pix_fix = 0;
	double pixelX = beginX;
	double pixelY = beginY;

	deltaX /= pixels; // 1
	deltaY /= pixels; // 0
	pix_fix = pixels;
	while (pixels)
	{
    	//my_mlx_pixel_put(data, pixelX, pixelY, color);
		mlx_pixel_put(mlx, win, pixelX, pixelY, color);
    	pixelX += 1;
    	pixelY = pow(pixelX, 2);
    	--pixels;
	}
	// while (pixels)
	// {
    // 	//my_mlx_pixel_put(data, pixelX, pixelY, color);
	// 	mlx_pixel_put(mlx, win, pixelX, pixelY, color);
    // 	pixelX -= deltaX;
    // 	pixelY += deltaY;
    // 	--pixels;
	// }
}

