/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rodcaeta <rodcaeta@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:37:20 by rodcaeta          #+#    #+#             */
/*   Updated: 2025/12/13 20:37:20 by rodcaeta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	gnl_strlen(const char *str)
{
	size_t i;

	i = 0;
	if (!str)
		return (0);
	while(str[i] && str[i] != '\n')
		i++;
	return(i);
}

char	*gnl_strjoin(const char *s1, const char *s2)
{
	size_t  sl1;
	size_t  sl2;
	char    *result;

	sl1 = ft_strlen(s1);
	sl2 = ft_strlen(s2);
	result = malloc(sl1 + sl2 + 1)
	if (!result)
	{
		free(s1);
		return (NULL);
	}
	gnl_memcpy(result, s1, sl1);
	gnl_memcpy(result + sl1, s2, sl2);
	result[sl1 + sl2] = '\0';
	free (s1);
	return (result);
}

char	*gnl_memcpy(void *dest, void *src, size_t len)
{
	char	*ndest;
	char	*nsrc;
	size_t	i;

	if (!dest || !src)
		return (NULL);
	ndest = (char *)dest;
	nsrc = (char *)src;
	i = 0;
	while (i < len)
	{
		ndest[i] = nsrc[i];
		i++;
	}
	return (dest);
}
int	gnl_clear_and_check(char *buffer)
{
	int i;
	int j;
	int	nl;
	
	i = 0;
	j = 0;
	nl = 0;
	while (buffer[i])
	{
		if (nl == 1)
			buffer[j++] = buffer[i];
		if (buffer[i] == '\n')
			nl = 1;
		buffer[i++] = 0;
	}
	return (nl);
}
