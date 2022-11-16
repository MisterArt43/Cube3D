/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   common_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abucia <abucia@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:49:31 by abucia            #+#    #+#             */
/*   Updated: 2022/11/16 08:16:43 by abucia           ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

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

void	skip_to_next_word(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] != ' ' && str[*i] != '\t' && str[*i] != '\r')
			break ;
		*i += 1;
	}
}

void	skip_to_eol_or_eof(char *str, int *i)
{
	while (str[*i])
	{
		if (str[*i] == '\n' || str[*i] == '\0')
			break ;
		*i += 1;
	}
}

void	skip_to_next_parse(t_game *game, int *i)
{
	while (game->fd_str[*i])
	{
		skip_to_next_word(game->fd_str, i);
		if (game->fd_str[*i] != '\n')
			break ;
		(*i)++;
	}
}
