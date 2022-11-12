/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:49:31 by abucia            #+#    #+#             */
/*   Updated: 2022/10/23 01:49:31 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while(str[i])
		i++;
	return (i);
}

char	*ft_freestrjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		len;

	i = 0;
	len = ft_strlen(s1) + ft_strlen(s2);
	res = malloc((len + 1) * sizeof(char));
	if (!res)
		return (NULL);
	if (s1)
	{
		while (s1[i])
		{
			res[i] = s1[i];
			i++;
		}
	}
	len = 0;
	if (s2)
		while (s2[len])
			res[i++] = s2[len++];
	res[i] = 0;
	free(s1);
	return (res);
}

int	ft_nstrncmp(const char *s1, const char *s2, size_t n, size_t start)
{
	if (ft_strlen(s1) < (int)start || ft_strlen(s2) < (int)start)
		return (1);
	while (s1[start] != '\0' && s2[start] != '\0' && start < n)
	{
		if ((unsigned char)s1[start] != (unsigned char)s2[start])
			return ((unsigned char)s1[start] - (unsigned char)s2[start]);
		start++;
	}
	if (start == n)
		return (0);
	return ((unsigned char)s1[start] - (unsigned char)s2[start]);
}

int	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (write(fd, &str[i], 1) == -1)
			break ;
		i++;
	}
	return (0);
}

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	a;

	a = 0;
	while (n != a)
	{
		((unsigned char *)s)[a] = c;
		a++;
	}
	return ((unsigned char *)s);
}

char	*ft_strdup(const char *s1)
{
	char	*cpy;
	size_t	i;

	i = 0;
	cpy = malloc((ft_strlen(s1) + 1) * sizeof(char));
	if (!cpy)
		return (NULL);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = 0;
	return (cpy);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t		i;
	char		*res;

	i = 0;
	if ((int)start > ft_strlen(s) + 1)
		return (ft_strdup(""));
	while (s[start + i] && i != len)
		i++;
	res = malloc((i + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	while (len != 0 && s[start])
	{
		res[i++] = s[start++];
		len--;
	}
	res[i] = 0;
	return (res);
}