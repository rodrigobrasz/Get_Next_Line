/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 15:16:58 by rodcaeta          #+#    #+#             */
/*   Updated: 2025/12/16 15:16:58 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);

static	void wait_for_enter(void)
{
	printf("\n\nPress enter:\n");
	fflush(stdout);
	while(getchar() != '\n')
		;
}

static	void test_one_file()
{
	int		fd;
	int		i;
	char	*line;

	fd = open("miquella1.txt", O_RDONLY);
	i = 1;
	printf("=====================================\n");
	printf("||                                 ||\n");
	printf("||     reading: miquella1.txt      ||\n");
	printf("||                                 ||\n");
	printf("=====================================\n");
	while (1)
	{
		line = get_next_line(fd);
		if(!line)
			break ;
		printf("[%d]: %s", i, line);
		free(line);
		i++;
	}
	if (fd >= 0)
		close(fd);
}

static	void test_empty_file()
{
	int		fd;
	char	*line;

	fd = open("empty.txt", O_RDONLY);
	line = get_next_line(fd);
	if (fd < 0)
	{
		printf("Error: Can't open empty.txt (skipped)\n");
		return ;
	}
	if(!line)
		printf("The file is empty. (correct behavior!)\n");
	else
	{
		printf("Expected a empty file, but returned: %s\n", line);
		free (line);
	}
	if (fd >= 0)
		close(fd);
}

int main(void)
{
	printf("=====================================\n");
	printf("||                                 ||\n");
	printf("||     GET_NEXT_LINE_TESTS         ||\n");
	printf("||                                 ||\n");
	printf("=====================================\n");
	wait_for_enter();
	test_one_file();
	wait_for_enter();
	printf("=====================================\n");
	printf("||                                 ||\n");
	printf("||     EMPTY FILE TEST             ||\n");
	printf("||                                 ||\n");
	printf("=====================================\n");
	wait_for_enter();
	test_empty_file();
	return (0);
}