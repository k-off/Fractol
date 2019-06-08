/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   main.c                                             :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/02/24 19:53:18 by pacovali      #+#    #+#                 */
/*   Updated: 2019/02/24 19:53:18 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			return_usage(char *file_name)
{
	ft_putstr("usage: ");
	ft_putstr(file_name);
	ft_putstr(" param1 [param2] ... [param10]\n");
	ft_putstr("\tparameters:\n");
	ft_putstr("\t\t\"-man\" - Mandelbrot set\n");
	ft_putstr("\t\t\"-jul\" - Julia fractal\n");
	ft_putstr("\t\t\"-ser\" - Sierpinski carpet\n");
	ft_putstr("\t\t\"-bar\" - Barnsley fern\n");
	exit(1);
}

void			run_fractal(t_all *all)
{
	if (all->name[0] == 'M')
		mandelbrot(all);
	else if (all->name[0] == 'J')
		julia(all);
	else if (all->name[0] == 'B')
		barnsley(all);
	else if (all->name[0] == 'S')
		serpinsky(all);
}

void			choose_fractal(int argc, char **argv)
{
	int			i;
	int			param[2];
	t_all		**all;

	i = 1;
	all = (t_all**)ft_memalloc(sizeof(t_all*) * 10);
	while (i < argc && i < 11)
	{
		if (!ft_strcmp(argv[i], "-man"))
			all[i - 1] = cre_all("Mandelbrot", i - 1);
		else if (!ft_strcmp(argv[i], "-jul"))
			all[i - 1] = cre_all("Julia", i - 1);
		else if (!ft_strcmp(argv[i], "-bar"))
			all[i - 1] = cre_all("Barnsley", i - 1);
		else if (!ft_strcmp(argv[i], "-ser"))
			all[i - 1] = cre_all("Sierpinski", i - 1);
		else
			return_usage(argv[0]);
		run_fractal(all[i - 1]);
		i++;
	}
	param[0] = i - 2;
	param[1] = 0;
	manage_windows(all, (void*)param, param[0]);
}

int				main(int argc, char **argv)
{
	if (argc > 1 && argc < 12)
		choose_fractal(argc, argv);
	else
		return_usage(argv[0]);
	return (0);
}
