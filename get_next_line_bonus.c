/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:36:26 by rodcaeta          #+#    #+#             */
/*   Updated: 2025/12/13 20:36:26 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*line;
	static char	buffer[FOPEN_MAX][BUFFER_SIZE + 1];

	if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (*buffer[fd] == 0)
		{
			bytes_read = read(fd, buffer[fd], BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
			buffer[fd][bytes_read] = '\0';
		}
		line = gnl_strjoin(line, buffer[fd]);
		if (gnl_clear_and_check(buffer[fd]) == 1)
			break ;
	}
	return (line);
}

/*
#include <fcntl.h>
#include <stdio.h>

int main(int ac, char **av)
{
	int		fd1;
	int 	fd2;
	char	*line1;
	char	*line2;
	int		i;
	int		j;
	(void) ac;

	i = 0;
	j = 0;

	fd1 = open(av[1], O_RDONLY);
	fd2 = open (av[2], O_RDONLY);
	if (fd1 < 0 || fd2 < 0)
	{
		printf("open failed");
		return (1);
	}
	while (1)
	{
		line1 = get_next_line(fd1);
		line2 = get_next_line(fd2);
		if(!fd1 && !fd2)
		{
			return (1);
		}
		if(line1)
		{
			printf("[%03d] = %s", ++i, line1);
			free(line1);
		}
		if(line2)
		{
			printf("[%03d] = %s", ++j, line2);
			free(line2);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}*/