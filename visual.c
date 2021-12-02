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

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;
	//int x = 0;
	//int y = 0;

	mlx = mlx_init(); /*establish a connection to the correct
	 graphical system and will return a void * which holds the location of our current MLX instance*/
	
	mlx_win = mlx_new_window(mlx, 1000, 1000, "pls lemme do this"); /*function, which will return 
	a pointer to the window we have just created. We can give the window height, width and a title. */
	
	img.img = mlx_new_image(mlx, 1000, 1000);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

//	my_mlx_pixel_put(&img, 5, 5, 0x0099FFFF);

	//draw_line(&img, 500, 500, 0, 0, 0x0099FFFF);
	draw_line(mlx, mlx_win, 0, 0, 10000, 10000, 0x0099FF);
		//mlx_put_image_to_window(mlx, mlx_win, img.img, x, y);
// 	draw_line(mlx, mlx_win, 250, 0, 500, 250, 0x00CCFF00);  //beg x y end x y 
// 	draw_line(mlx, mlx_win, 500, 250, 250, 500, 0x00CC0099);  //beg x y end x y 
// 	draw_line(mlx, mlx_win, 250, 500, 0, 250, 0x0000FFFF);  //beg x y end x y 
// //	sleep(1);
// //	draw_line(mlx, mlx_win, 0, 250, 250, 0, 0x00FFFF99);

	mlx_loop(mlx); //initiate the window rendering
}