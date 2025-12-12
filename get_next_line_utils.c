/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 14:30:56 by marvin            #+#    #+#             */
/*   Updated: 2025/12/08 14:30:56 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

size_t    ft_strlen(const char *str)
{
    size_t i;

    i = 0;
    while(str[i])
    {
        i++;
    }
    return (i);
}

const char  *ft_strchr(const char *str, int c)
{
	int		i;
	char	tofchr;

	tofchr = (char) c;
	i = 0;
	while (str[i])
	{
		if (str[i] == tofchr)
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == tofchr)
		return ((char *)&str[i]);
	return (NULL);
}

void	ft_bzero(void *s, size_t n)
{
	char	*tmp_ptr;

	tmp_ptr = (char *)s;
	while (n > 0)
	{
		*(tmp_ptr++) = 0;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*dest;
	
	if(size == 0)
		return(malloc(0));
	if(nmemb > SIZE_MAX / size)
		return (NULL);
	dest = malloc(nmemb * size);
	if(!dest)
		return (NULL);
	ft_bzero(dest, nmemb * size);
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{

}