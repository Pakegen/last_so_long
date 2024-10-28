/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verification.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 10:44:05 by quenalla          #+#    #+#             */
/*   Updated: 2024/10/28 14:16:37 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

void	ft_verification(t_data *data)
{
	ft_verification_lenght(&data);
	ft_verification_wall(&data);
	ft_verification_exit(&data);
	ft_verification_player(&data);
	ft_verification_collectible(&data);
}

int	ft_verification_fichier(t_data *init, char **av)
{
	int	i;

	init->map->name = av[1];
	i = ft_strlen(init->map->name);
	if (i <= 4)
		return (0);
	if (init->map->name[--i] != 'r')
		return (0);
	if (init->map->name[--i] != 'e')
		return (0);
	if (init->map->name[--i] != 'b')
		return (0);
	if (init->map->name[--i] != '.')
		return (0);
	return (1);
}

void	ft_verification_lenght(t_data *data)
{
	int		fd;
	char	*read;
	int		i;
	int		k;

	fd = open(data->map->name, O_RDONLY);
	if (!fd)
		ft_exit();
	read = "";
	i = 0;
	k = 0;
	while (read != NULL)
	{
		if (k != i)
			ft_exit();
		read = get_next_line(fd);
		if (i == 0)
			k = ft_strlen(read);
		i = ft_strlen(read);
	}
	close(fd);
}

void	ft_verification_wall(t_data *data)
{
	int		fd;
	int		i;

	fd = open(data->map->name, O_RDONLY);
	if (!fd)
		ft_exit();
	while (read != NULL)
	{
		data->map->map[data->map->y][data->map->x];
	}
}
