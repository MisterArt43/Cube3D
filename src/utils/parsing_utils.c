/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vducoulo <vducoulo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 01:53:33 by abucia            #+#    #+#             */
/*   Updated: 2022/11/16 15:25:18 by vducoulo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/header.h"

void	stop_mlx(t_game *game)
{
	if (ON_LINUX)
	{
		mlx_destroy_display(game->mlx);
		free(game->mlx);
	}
}

void	ft_ermap(char *str, void *ptr, t_game *game)
{
	int		i;
	size_t	res;

	if (ptr != NULL)
		free(ptr);
	stop_mlx(game);
	free(game);
	i = 0;
	write(2, "Error\n", 6);
	if (!str)
		exit(EXIT_FAILURE);
	while (str[i])
	{
		res = write(2, &str[i], 1);
		if (res == 0)
			break ;
		i++;
	}
	exit(EXIT_FAILURE);
}

void	read_error(int fd, char *str, char *er, t_game *game)
{
	close(fd);
	ft_ermap(er, str, game);
}

char	*ft_readall(int fd, t_game *game)
{
	char	*all;
	char	*buffer;
	int		i;

	if (fd == -1)
		ft_ermap("can't open this file\n", NULL, game);
	all = NULL;
	buffer = malloc((17) * sizeof(char));
	if (!buffer)
		return (NULL);
	i = 1;
	while (i != 0)
	{
		i = read(fd, buffer, 16);
		if (i == -1)
			read_error(fd, buffer, \
			"an error occurred while reading the file\n", game);
		buffer[i] = '\0';
		all = ft_freestrjoin(all, buffer);
		if (!all)
			read_error(fd, buffer, \
			"an error occurred while reading the file\n", game);
	}
	free(buffer);
	return (all);
}
