/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: pacovali <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/01/12 17:38:53 by pacovali      #+#    #+#                 */
/*   Updated: 2019/01/17 19:03:52 by pacovali      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	fk_new_norm(char *s, long long int *m, int *i, int *isneg)
{
	if (*m == 0)
	{
		(*i)--;
		s[*i] = '0';
	}
	while (*m != 0)
	{
		(*i)--;
		s[*i] = (*m % 10) + '0';
		*m /= 10;
	}
	if (*isneg == -1)
	{
		(*i)--;
		s[*i] = '-';
	}
}

void		ft_putnbr_fd(int n, int fd)
{
	char			s[12];
	int				isneg;
	int				i;
	long long int	m;

	i = 12;
	m = n;
	i--;
	s[i] = '\0';
	isneg = 1;
	if (m < 0)
	{
		m = -m;
		isneg = -1;
	}
	fk_new_norm(s, &m, &i, &isneg);
	while (i < 11)
	{
		write(fd, &s[i], 1);
		i++;
	}
}
