/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 16:48:00 by malton            #+#    #+#             */
/*   Updated: 2021/11/04 16:23:16 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	f;

	if (!s)
		return (0);
	f = 0;
	while (s[f] != '\0')
	{
		if (s[f] == (char)c)
			return ((char *)&s[f]);
		f++;
	}
	return (0);
}

char	*ft_strjoin(char *str1, char *str2)
{
	size_t	i;
	size_t	n;
	char	*res;

	if (!str1)
	{
		str1 = (char *)malloc(sizeof(char));
		str1[0] = '\0';
	}
	if (!str1 || !str2)
		return ((void *)0);
	res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
	if (!res)
		return ((void *)0);
	i = -1;
	n = 0;
	if (str1)
		while (str1[++i] != '\0')
			res[i] = str1[i];
	while (str2[n] != '\0')
		res[i++] = str2[n++];
	res[i] = '\0';
	free(str1);
	return (res);
}

char	*get_line(char *str)
{
	int		i;
	char	*res;

	i = 0;
	if (!str[i])
		return ((void *)0);
	while (str[i] && str[i] != '\n')
		i++;
	res = (char *)malloc(sizeof(char) * (i + 2));
	if (!res)
		return ((void *)0);
	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		res[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		res[i] = str[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*update_str(char *str)
{
	int		i;
	int		n;
	char	*res;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
	{
		free(str);
		return ((void *)0);
	}
	res = (char *)malloc(sizeof(char) * (ft_strlen(str) - i));
	if (!res)
		return ((void *)0);
	i++;
	n = 0;
	while (str[i] != '\0')
		res[n++] = str[i++];
	res[n] = '\0';
	free(str);
	return (res);
}
