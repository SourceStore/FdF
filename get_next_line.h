/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rishchen <rishchen@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 16:16:02 by rishchen          #+#    #+#             */
/*   Updated: 2017/02/07 16:16:05 by rishchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft/libft.h"
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/stat.h>
# include <fcntl.h>
# define BUFF_SIZE 32

typedef struct		s_llist
{
	int				filedis;
	char			*buffer;
	char			*buff;
	char			*ans;
	struct s_llist	*next;
}					t_llist;

int					get_next_line(const int fd, char **line);
int					ft_cc(char *str, int c);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strnew(size_t size);
size_t				ft_strlen(const char *s);
void				ft_strdel(char **as);
void				ft_bzero(void *s, size_t n);

#endif
