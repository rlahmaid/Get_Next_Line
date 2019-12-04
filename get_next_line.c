/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhastaf <akhastaf@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:10:57 by rlahmaid          #+#    #+#             */
/*   Updated: 2019/12/04 16:35:36 by akhastaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include<string.h>
#include <fcntl.h>
#include <unistd.h>
#include "get_next_line.h"

int		ft_readline(int fd, char **gard)
{
	char	*buf;
	char	*tmp;
	int		n;

	if (!(buf = malloc(BUFFER_SIZE + 1 )) || (read(fd, NULL, 0) == -1))
	{
		if (buf)
			free(buf);
		return (-1);
	}
	while ((n = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[n] = '\0';
		tmp = strdup(*gard);
		free(*gard);
		if (!(*gard = ft_strjoin(tmp, buf)))
				return (-1);
		free(tmp);
		if (ft_strchr(*gard, '\n'))
			break ;
	}
	free(buf);
	return (n);
}

int get_next_line(int fd, char **line)
{
	static char *gard;
	char *s;
	int n;
	char	*tmp;

	if (!gard)
		gard = ft_strdup("");
	if ((n = ft_readline(fd, &gard)) < 0)
		return (-1);
	if ((s = ft_strchr(gard, '\n')))
    {
        *line = ft_strndup(gard, s - gard);
		tmp = ft_strdup(strchr(gard, '\n') + 1);
		free(gard);
		gard = ft_strdup(tmp);
		free(tmp);
        return (1);
    }
	if (!n && gard)
	{
		*line = ft_strdup(gard);
		free(gard);
		gard = NULL;
	}
	return 0;
}