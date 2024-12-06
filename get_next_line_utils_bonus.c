/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nneto-de <nneto-de@student.42porto.com     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 14:51:08 by nneto-de          #+#    #+#             */
/*   Updated: 2023/05/24 15:26:26 by nneto-de         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, const char *s2)
{
	size_t	i;
	size_t	j;
	char	*ptr;

	i = 0;
	j = 0;
	ptr = (char *)malloc((sizeof(char const)) * (ft_strlen(s1)
				+ ft_strlen(s2) + 1));
	if (ptr == NULL)
		return (NULL);
	if (s1)
	{
		while (s1[i] != '\0')
		{
			ptr[i] = s1[i];
			i++;
		}
	}
	while (s2[j] != '\0')
	{
		ptr[i++] = s2[j++];
	}
	ptr[i] = '\0';
	free (s1);
	return (ptr);
}

char	*ft_strchr(const char *s, int c)
{
	size_t		i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}	
	return (NULL);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (src[len])
		len++;
	if (!size)
		return (len);
	while ((src[i] != '\0') && (i < (size -1)) && i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
