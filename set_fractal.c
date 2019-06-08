/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   set_fractal.c                                      :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 19:53:18 by pacovali      #+#    #+#                 */
/*   Updated: 2019/02/24 19:53:18 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static t_set	*creat_set(char *s)
{
	t_set	*set;

	set = (t_set*)ft_memalloc(sizeof(t_set) * 1);
	set->x_off = 0.0f;
	set->y_off = 0.0f;
	if (s[0] == 'J' || s[0] == 'M')
		set->scl = (long double)(960 / 3.5f);
	else if (s[0] == 'S')
		set->scl = 729.0f;
	else
		set->scl = 550.0f;
	set->scl_0 = 0.0;
	set->detail = 15;
	set->p = 1;
	set->x = 0.0f;
	set->y = 0.0f;
	return (set);
}

static void		set_colors(int colors[12])
{
	colors[0] = 0xff0000;
	colors[1] = 0xffff00;
	colors[2] = 0x00ff00;
	colors[3] = 0x00ffff;
	colors[4] = 0x0000ff;
	colors[5] = 0xff00ff;
	colors[6] = 0x880000;
	colors[7] = 0x888800;
	colors[8] = 0x008800;
	colors[9] = 0x008888;
	colors[10] = 0x000088;
	colors[11] = 0x880088;
}

static void		set_win_size(char *s, t_all *all)
{
	if (s[0] == 'S')
	{
		all->win_width = 729;
		all->win_height = 729;
	}
	else if (s[0] == 'B')
	{
		all->win_width = 480;
		all->win_height = 550;
	}
	else
	{
		all->win_width = 960;
		all->win_height = 550;
	}
}

t_all			*cre_all(char *s, int arg_n)
{
	t_all		*all;

	all = (t_all*)ft_memalloc(sizeof(t_all) * 1);
	all->arg_nr = arg_n;
	all->win = (t_win*)ft_memalloc(sizeof(t_win*) * 1);
	all->win->mlx_ptr = mlx_init();
	set_win_size(s, all);
	if (s[0] == 'S')
		all->win->win_ptr = \
		mlx_new_window(all->win->mlx_ptr, all->win_width, all->win_height, s);
	else if (s[0] == 'B')
		all->win->win_ptr = \
		mlx_new_window(all->win->mlx_ptr, all->win_width, all->win_height, s);
	else
		all->win->win_ptr = \
		mlx_new_window(all->win->mlx_ptr, all->win_width, all->win_height, s);
	all->name = ft_strdup(s);
	all->set = creat_set(all->name);
	set_colors(all->colors);
	all->win_qty = 0;
	return (all);
}
