/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   additionalfunc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/20 20:36:04 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/21 21:48:11 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			range_x(char **line)
{
	int		counter;

	counter = 0;
	if (line)
	{
		while (line[counter] != '\0')
			counter++;
	}
	return (counter);
}

double		ft_atoi_base(char *s, int flag, int i)
{
	char	*alph;
	double	answer;
	int		j;
	int		l;

	answer = 0;
	alph = "0123456789abcdefABCDEF";
	if (flag == 0)
		answer = ft_atoi(s);
	else if (flag == 1)
	{
		j = ft_cc(alph, s[i * 2]);
		l = ft_cc(alph, s[i * 2 + 1]);
		j = j <= 15 ? j % 16 : (j % 16) + 10;
		l = l <= 16 ? l % 16 : (l % 16) + 10;
		answer = j * 16 + l;
	}
	return (answer);
}

int			close_window(int keykode)
{
	if (keykode == 53 || keykode == 65307)
		exit(0);
	return (0);
}

int			exit_x(void *param)
{
	param = NULL;
	exit(0);
	return (0);
}

void		ft_swap(double *par1, double *par2)
{
	double	var;

	var = *par1;
	*par1 = *par2;
	*par2 = var;
}
