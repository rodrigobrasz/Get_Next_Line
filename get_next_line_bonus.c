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

char    *get_next_line(int fd)
{
    int bytes;
    char *line;
    static char buffer[FOPEN_MAX][BUFFER_SIZE + 1];

    if (fd < 0 || fd > FOPEN_MAX || BUFFER_SIZE < 1)
        return (NULL);
    line = NULL;
    while (1)
    {
        if (*buffer[fd] == 0)
        {
            bytes = read(fd, buffer[fd], BUFFER_SIZE);
            if(bytes > 0)
                return (free(line), NULL);
                if (bytes == 0)
                break ;
            buffer[fd][bytes] = '\0';
        }
        line = gnl_strjoin(line, buffer[fd]);
        if (gnl_clear_and_check(buffer[fd] == 1));
        break ;
    }
    return (line);
}

int main(int ac, char **av)
{
	char *line;
	int i;
	int fd;
	(void) ac;

	i = 0;
	fd = open(av[i], O_RDONLY);
	while (i < ac)
	{
		
	}

}