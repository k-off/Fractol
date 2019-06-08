/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   barnsley.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		bar_prob(double *x, double *y, int prob)
{
	double x_tmp;
	double y_tmp;

	if (prob < 1)
	{
		x_tmp = 0;
		y_tmp = 0.16 * *y;
	}
	else if (prob < 86)
	{
		x_tmp = 0.85 * *x + 0.04 * *y;
		y_tmp = -0.04 * *x + 0.85 * *y + 1.6;
	}
	else if (prob < 93)
	{
		x_tmp = 0.2 * *x - 0.26 * *y;
		y_tmp = 0.23 * *x + 0.22 * *y + 1.6;
	}
	else
	{
		x_tmp = -0.15 * *x + 0.28 * *y;
		y_tmp = 0.26 * *x + 0.24 * *y + 0.44;
	}
	*x = x_tmp;
	*y = y_tmp;
}

static void		set_black(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	while (y < all->win_height)
	{
		x = 0;
		while (x < all->win_width)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, x, y, 0);
			x++;
		}
		y++;
	}
}

void			*barnsley(t_all *all)
{
	long double		i;
	int				x;
	int				y;
	int				color;
	long double		max_iter;

	srand(100);
	i = 0;
	set_black(all);
	color = all->colors[all->arg_nr];
	max_iter = (all->win_width * all->win_height \
			* pow(all->set->scl_0 * (all->set->scl_0) + 1, 1.5));
	while (i < max_iter)
	{
		x = 480 - (int)(240 + 0.1 * all->set->scl * pow(2, all->set->scl_0) \
			* (all->set->x + all->set->x_off * pow(2, all->set->scl_0)));
		y = 550 - (int)(0.1 * all->set->scl * pow(2, all->set->scl_0) \
			* (all->set->y + all->set->y_off * pow(2, all->set->scl_0)));
		if (x > -1 && x < all->win_width && y > -1 && y < all->win_height)
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, x, y, color);
		bar_prob(&all->set->x, &all->set->y, rand() % 100);
		i++;
	}
	return (NULL);
}
