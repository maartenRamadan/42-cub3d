/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_split.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: mramadan <mramadan@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/04 12:07:13 by mramadan       #+#    #+#                */
/*   Updated: 2019/11/13 14:56:53 by mramadan      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int		count_word_length(char *str, char c)
{
	int i;
	int wlen;

	i = 0;
	wlen = 0;
	while (str[i] == c)
		i++;
	while (str[i] != '\0' && str[i] != c)
	{
		wlen++;
		i++;
	}
	return (wlen);
}

static int		count_words(char *str, char c)
{
	int i;
	int count;
	int x;

	i = 0;
	count = 0;
	x = 0;
	while (str[i] != '\0')
	{
		while (str[i] != c && str[i] != '\0')
		{
			i++;
			x = 1;
		}
		if (str[i] == c)
		{
			count += (x == 1) ? 1 : 0;
			x = 0;
			i++;
		}
		else if (str[i] == '\0')
			count += (x == 1) ? 1 : 0;
	}
	return (count);
}

static char		**free_all(char **array, int i)
{
	while (array)
	{
		i--;
		free(array[i]);
	}
	free(array);
	return (0);
}

static char		*write_array(const char *s, char c)
{
	int		di;
	int		i;
	char	*dynstr;

	i = 0;
	di = 0;
	dynstr = (char*)malloc(count_word_length((char*)s, c) + 1);
	if (!dynstr)
		return (0);
	while (s[i] && s[i] != c)
	{
		dynstr[di] = s[i];
		i++;
		di++;
	}
	dynstr[di] = '\0';
	return (dynstr);
}

char			**ft_split(char const *s, char c)
{
	char	**array;
	int		i;

	if (!s)
		return (0);
	array = (char**)malloc(sizeof(char*) * (count_words((char*)s, c) + 1));
	if (!array)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s && *s != c)
		{
			array[i] = write_array(s, c);
			if (array[i] == 0)
				return (free_all(array, i));
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	array[i] = NULL;
	return (array);
}
