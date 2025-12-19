/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:37:40 by rodcaeta          #+#    #+#             */
/*   Updated: 2025/12/13 20:37:40 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H 
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

size_t	gnl_strlen(const char *str);
char	*gnl_strjoin(char *s1, char *s2);
void	*gnl_memcpy(void *dest, void *src, size_t len);
int		gnl_clear_and_check(char *buffer);

#endif
