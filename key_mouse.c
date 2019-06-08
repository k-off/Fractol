/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   key_mouse.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 19:53:18 by pacovali      #+#    #+#                 */
/*   Updated: 2019/02/24 19:53:18 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void		ft_zoom(t_all *all, int sign, int x, int y)
{
	long double map_x;
	long double map_y;

	map_x = x / (all->set->scl * pow(3, all->set->scl_0)) + all->set->x_off;
	map_y = y / (all->set->scl * pow(3, all->set->scl_0)) + all->set->y_off;
	if (sign > 0 && all->set->scl_0 < 16)
		all->set->scl_0++;
	else if (all->set->scl_0 > 0)
		all->set->scl_0--;
	else
		return ;
	if (all->name[0] == 'S')
	{
		all->set->x_off = map_x - \
		(x / (all->set->scl * pow(3, all->set->scl_0)));
		all->set->y_off = map_y - \
		(y / (all->set->scl * pow(3, all->set->scl_0)));
	}
}

static int		mouse_move(int x, int y, t_all *all)
{
	all->set->x = (x - all->win_width / 2) / (all->set->scl \
					* pow(3, all->set->scl_0)) - all->set->x_off;
	all->set->y = (x - all->win_height / 2) / (all->set->scl \
					* pow(3, all->set->scl_0)) - all->set->x_off;
	all->mouse_x = x;
	all->mouse_y = y;
	run_fractal(all);
	return (0);
}

static int		deal_keys(int key, t_all *all)
{
	long double		offset;

	offset = (50 / all->set->scl / pow(3, all->set->scl_0));
	if (key == 123)
		all->set->x_off += offset;
	else if (key == 124)
		all->set->x_off -= offset;
	else if (key == 126)
		all->set->y_off += offset;
	else if (key == 125)
		all->set->y_off -= offset;
	else if (key == 43 && all->set->detail > 30)
		all->set->detail -= 30;
	else if (key == 47)
		all->set->detail += 30;
	else if (key == 69)
		ft_zoom(all, 1, all->win_width / 2, all->win_height / 2);
	else if (key == 78)
		ft_zoom(all, -1, all->win_width / 2, all->win_height / 2);
	else if (key == 53)
		exit(0);
	run_fractal(all);
	return (0);
}

static int		deal_mouse(int key, int x, int y, t_all *all)
{
	if (key == 4)
		ft_zoom(all, -1, x, y);
	if (key == 5)
		ft_zoom(all, 1, x, y);
	if (all->name[0] == 'J' \
		&& (x != all->mouse_x || y != all->mouse_y))
	{
		all->set->x = (x - all->win_width / 2) / (all->set->scl \
						* pow(3, all->set->scl_0)) - all->set->x_off;
		all->set->y = (x - all->win_height / 2) / (all->set->scl \
						* pow(3, all->set->scl_0)) - all->set->x_off;
		all->mouse_x = x;
		all->mouse_y = y;
	}
	run_fractal(all);
	return (0);
}

void			manage_windows(t_all **all, int param[2], int win_qty)
{
	win_qty = 1;
	mlx_mouse_hook(all[param[1]]->win->win_ptr,
		&deal_mouse, (void*)all[param[1]]);
	mlx_key_hook(all[param[1]]->win->win_ptr,
		&deal_keys, all[param[1]]);
	mlx_hook(all[param[1]]->win->win_ptr, 6, 0,
		&mouse_move, (void*)all[param[1]]);
	mlx_loop(all[param[1]]->win->mlx_ptr);
}
