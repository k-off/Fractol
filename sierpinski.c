/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   sierpinski.c                                       :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		choose_color(t_all *all, int x, int y)
{
	int		t_x;
	int		t_y;

	t_x = fabsl(x + (all->set->x_off * all->set->scl \
						* pow(3, all->set->scl_0)));
	t_y = fabsl(y + (all->set->y_off * all->set->scl \
						* pow(3, all->set->scl_0)));
	if (t_x % (int)pow(3, all->set->p) >= (int)pow(3, all->set->p - 1)
		&& t_x % (int)pow(3, all->set->p) < 2 * (int)pow(3, all->set->p - 1)
		&& t_y % (int)pow(3, all->set->p) >= (int)pow(3, all->set->p - 1)
		&& t_y % (int)pow(3, all->set->p) < 2 * (int)pow(3, all->set->p - 1))
		return (1);
	else
	{
		if (all->set->p > 0)
		{
			all->set->p--;
			return (choose_color(all, x, y));
		}
	}
	return (0);
}

void			*serpinsky(t_all *all)
{
	int		color;
	int		x;
	int		y;

	y = 0;
	while (y < all->win_height)
	{
		x = 0;
		while (x < all->win_width)
		{
			all->set->p = 7 + (int)(round(all->set->scl_0));
			color = choose_color(all, x, y);
			if (color)
				color = all->colors[(12 - all->set->p \
						+ (int)all->set->scl_0) % 12];
			else
				color = 0xffffff;
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, x, y, color);
			x++;
		}
		y++;
	}
	return (NULL);
}
