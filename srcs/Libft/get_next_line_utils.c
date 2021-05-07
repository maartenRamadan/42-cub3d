/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/07 16:12:41 by mramadan       #+#    #+#                */
/*   Updated: 2020/01/24 15:02:55 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

size_t	gnl_ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0' && s[i] != '\n')
		i++;
	return (i);
}

size_t	gnl_ft_strlen2(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*gnl_ft_strdup(char *s1)
{
	int		i;
	char	*str2;

	i = 0;
	str2 = malloc(sizeof(*str2) * (gnl_ft_strlen2(s1) + 1));
	if (!str2)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str2[i] = s1[i];
		i++;
	}
	str2[i] = '\0';
	return (str2);
}

char	*gnl_ft_strchr(char *s, int c)
{
	while (*s)
	{
		if (*s == c)
			return (s + 1);
		s++;
	}
	if (c == '\0')
		return (s);
	return (0);
}

char	*gnl_ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		i2;

	i = 0;
	i2 = 0;
	if (!s1 && !s2)
		return (0);
	s3 = (char*)malloc(sizeof(char) * (gnl_ft_strlen2(s1) +
	gnl_ft_strlen2(s2) + 1));
	if (!s3)
		return (0);
	while (s1[i] != '\0')
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[i2] != '\0')
	{
		s3[i] = s2[i2];
		i++;
		i2++;
	}
	s3[i] = '\0';
	return (s3);
}
