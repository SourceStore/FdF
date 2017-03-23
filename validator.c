/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/21 21:19:16 by rishchen          #+#    #+#             */
/*   Updated: 2017/03/23 16:19:30 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			ft_in(char *found, char *str, int j)
{
	int		i;

	i = -1;
	if (str[j + 1] != 'x' || str[j] != '0')
		return (0);
	str = (str + j + 2);
	if (ft_strlen(str) > 6)
		return (0);
	while (*str)
	{
		while (++i <= (int)ft_strlen(found))
		{
			if (found[i] == *str || ft_isdigit(*str))
				break ;
			else if (i == (int)ft_strlen(found))
				return (0);
		}
		i = -1;
		str++;
	}
	return (1);
}

int			incor_char(char **arr)
{
	int		j;
	int		i;
	int		c;

	i = 0;
	j = 0;
	while (arr[j])
	{
		c = ft_cc(arr[j], ',');
		while (arr[j][i])
		{
			if (!ft_isdigit(arr[j][i]) && arr[j][0] != '-' && i != c)
				return (0);
			else if (i > c && c != -1)
			{
				if (!(ft_in("ABCDEFabcdef", arr[j], i)))
					return (0);
				break ;
			}
			i++;
		}
		i = 0;
		j++;
	}
	return (1);
}

int			count_range_mas(char **line2, int cline)
{
	int		i;

	if (cline != -1)
		return (cline);
	i = -1;
	while (line2[++i])
		;
	return (i);
}

int			check_arr(int fd)
{
	int		cline;
	char	**line2;
	char	*line;
	int		i;
	int		flag;

	i = 0;
	line = NULL;
	cline = -1;
	while (get_next_line(fd, &line) > 0)
	{
		line2 = ft_strsplit(line, ' ');
		cline = count_range_mas(line2, cline);
		if (*line != '\0' && line2[0] != NULL)
			i++;
		free(line);
		flag = count_range_mas(line2, -1);
		if (incor_char(line2) == 0 || cline != flag)
			return (0);
		ft_strdel(line2);
	}
	return (i);
}
