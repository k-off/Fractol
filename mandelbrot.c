/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   mandelbrot.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int			is_in_cardioid(double x_0, double y_0)
{
	long double		card;

	card = pow((x_0 - 0.25), 2) + pow(y_0, 2);
	if (card * (card + (x_0 - 0.25)) <= 0.25 * pow(y_0, 2))
		return (1);
	if (pow((x_0 + 1), 2) + pow(y_0, 2) <= 0.125)
		return (1);
	return (0);
}

static unsigned int	check_bro(int x_0, int y_0, t_set *set, t_all *all)
{
	long double		tmp_x;
	long double		x;
	long double		y;
	int				i;

	i = 0;
	x = 0.0f;
	y = 0.0f;
	if (!is_in_cardioid((double)((x_0 - (int)(all->win_width / 3.5 * 2.5)) \
		/ (set->scl * pow(3, set->scl_0)) - set->x_off), \
		(double)((y_0 - all->win_height / 2) / (set->scl * pow(3, set->scl_0)) \
		+ set->y_off)))
		while (i < set->detail && ((x * x + y * y) < 4))
		{
			tmp_x = x * x - y * y + (double)(x_0 - (int)(all->win_width \
				/ 3.5 * 2.5)) / (set->scl * pow(3, set->scl_0)) - set->x_off;
			y = 2 * x * y + (double)(y_0 - all->win_height / 2) / (set->scl * \
				pow(3, set->scl_0)) + set->y_off;
			x = tmp_x;
			i++;
		}
	if (i == set->detail)
		return (0);
	return (i);
}

void				*mandelbrot(t_all *all)
{
	int				x;
	int				y;
	unsigned int	color;

	y = 0;
	while (y < all->win_height)
	{
		x = 0;
		while (x < all->win_width)
		{
			color = check_bro(x, y, all->set, all) * 659;
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, \
				x, y, color);
			x += 1;
		}
		y += 1;
	}
	return (NULL);
}
