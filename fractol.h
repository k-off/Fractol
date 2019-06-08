/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   fractol.h                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/03/05 15:06:09 by pacovali      #+#    #+#                 */
/*   Updated: 2019/03/05 15:06:09 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FRACTOL_H
# define __FRACTOL_H

# include "libft/libft.h"
# include <stdlib.h>
# include <math.h>
# include "lmlx/mlx.h"
# include <sys/types.h>
# include <unistd.h>

typedef struct		s_win
{
	void			*mlx_ptr;
	void			*win_ptr;
}					t_win;

typedef struct		s_curr_sett
{
	long double		x_off;
	long double		y_off;
	long double		scl_0;
	long double		scl;
	int				detail;
	int				p;
	double			x;
	double			y;

}					t_set;

typedef struct		s_all
{
	char			*name;
	int				arg_nr;
	int				win_qty;
	t_win			*win;
	t_set			*set;
	int				colors[12];
	int				mouse_x;
	int				mouse_y;
	int				win_width;
	int				win_height;
	int				x;
	int				y;
}					t_all;

void				*serpinsky(t_all *all);
void				*julia(t_all *all);
void				*mandelbrot(t_all *all);
void				*barnsley(t_all *all);
void				return_usage(char *file_name);
t_all				*cre_all(char *s, int arg_n);
void				manage_windows(t_all **all, int param[2], int win_qty);
void				run_fractal(t_all *all);
void				choose_fractal(int	argc, char **argv);
int					main(int argc, char **argv);

#endif
