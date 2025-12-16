/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:17:18 by rodcaeta          #+#    #+#             */
/*   Updated: 2025/12/16 15:17:18 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	int			bytes_read;
	char		*line;
	static char	buffer[BUFFER_SIZE + 1];

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	line = NULL;
	while (1)
	{
		if (*buffer == 0)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read < 0)
				return (free(line), NULL);
			if (bytes_read == 0)
				break ;
			buffer[bytes_read] = '\0';
		}
		line = gnl_strjoin(line, buffer);
		if (gnl_clear_and_check(buffer) == 1)
			break ;
	}
	return (line);
}
