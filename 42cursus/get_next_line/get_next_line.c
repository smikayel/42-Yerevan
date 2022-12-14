/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smikayel <smikayel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 19:03:10 by smikayel          #+#    #+#             */
/*   Updated: 2022/04/03 14:08:33 by smikayel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	endl_index(char *stash)
{
	int	i;

	i = 0;
	while (stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (i);
		i++;
	}
	return (0);
}

char	*get_line_from_stack(char **l, char **s)
{
	char	*line;
	char	*stash;
	char	*ptr;

	line = *l;
	stash = *s;
	line = ft_substr(stash, 0, endl_index(stash) + 1);
	ptr = stash;
	stash = ft_substr(stash, endl_index(stash) + 1, ft_strlen(stash));
	free(ptr);
	*l = line;
	*s = stash;
	return (*l);
}

char	*if_not_byte(char **line, char **stash)
{
	char	*ptr;

	if (!*stash || **stash == '\0')
	{
		free(*stash);
		return (NULL);
	}
	else if (is_endl(*stash) == 1)
	{
		get_line_from_stack(line, stash);
		return (*line);
	}
	else
	{
		*line = ft_strdup(*stash);
		ptr = *stash;
		free(*stash);
		*stash = NULL;
		return (*line);
	}
}

char	*get_next_line(int fd)
{
	int			bytes;
	char		buff[BUFFER_SIZE + 1];
	static char	*stash;
	char		*line;

	while (1)
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		buff[bytes] = '\0';
		if (bytes == -1)
			return (NULL);
		if (bytes > 0)
		{
			if (!stash)
				stash = ft_strdup(buff);
			else
				stash = ft_strjoin(stash, buff);
			if (is_endl(stash) == 1)
				break ;
		}
		else
			return (if_not_byte(&line, &stash));
	}
	return (get_line_from_stack(&line, &stash));
}
