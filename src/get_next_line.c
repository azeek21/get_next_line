/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: malton <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 18:03:37 by malton            #+#    #+#             */
/*   Updated: 2021/11/01 18:59:11 by malton           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*read_file(int fd, char *str)
{
	char	*temp;
	int		done;

	temp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!temp)
		return ((void *)0);
	done = 1;
	while (!ft_strchr(str, '\n') && done != 0)
	{
		done = read(fd, temp, BUFFER_SIZE);
		if (done == -1)
		{
			free(temp);
			return ((void *)0);
		}
		temp[done] = '\0';
		str = ft_strjoin(str, temp);
	}
	free(temp);
	return (str);
}

char	*get_next_line(int fd)
{
	char		*res;
	static char	*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	str = read_file(fd, str);
	if (!str)
		return ((void *)0);
	res = get_line(str);
	str = update_str(str);
	return (res);
}
