/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:51:12 by nneto-de          #+#    #+#             */
/*   Updated: 2023/05/24 15:13:55 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42

# endif
# ifndef OPEN_MAX
#  define OPEN_MAX 10000

# endif
# include<stdio.h>
# include<unistd.h>
# include<stddef.h>
# include<string.h>
# include<ctype.h>
# include<stdlib.h>
# include<errno.h>
# include<fcntl.h>

size_t	ft_strlen(const char *s);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strchr(const char *s, int c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
char	*get_next_line(int fd);

#endif