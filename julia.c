/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   julia.c                                            :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/01 00:42:00 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/01 00:42:01 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int		check_jul(long double x, long double y, t_set *set)
{
	long double	tmp_x;
	long double	tmp_y;
	long double	x_0;
	long double	y_0;
	int			i;

	i = 0;
	x_0 = set->x;
	y_0 = set->y;
	while (i < set->detail && ((x * x + y * y) < 4))
	{
		tmp_x = x * x - y * y + x_0;
		tmp_y = 2 * x * y + y_0;
		x = tmp_x;
		y = tmp_y;
		i++;
	}
	return (i);
}

static int		find_dbl(int x, int y, t_all *all)
{
	long double	x_0;
	long double	y_0;
	int			check;

	x_0 = (x - (all->win_width / 2)) \
	/ (all->set->scl * pow(3, all->set->scl_0)) - all->set->x_off;
	y_0 = (y - (all->win_height / 2)) \
	/ (all->set->scl * pow(3, all->set->scl_0)) + all->set->y_off;
	check = check_jul(x_0, y_0, all->set);
	return (check);
}

void			*julia(t_all *all)
{
	int	x;
	int	y;

	y = 0;
	all->set->scl = all->set->scl * 1;
	while (y < all->win_height)
	{
		x = 0;
		while (x < all->win_width)
		{
			mlx_pixel_put(all->win->mlx_ptr, all->win->win_ptr, \
				x, y, find_dbl(x, y, all) * 659);
			x += 1;
		}
		y += 1;
	}
	return (NULL);
}
