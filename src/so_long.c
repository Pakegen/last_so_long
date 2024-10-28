/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 17:56:44 by qacjl             #+#    #+#             */
/*   Updated: 2024/10/28 15:05:21 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"so_long.h"

/*void	map_initialise(t_map *init, char *av)
{
	init->name = av;
	init->moves = 0;
	init->p = 0;
	init->c = 0;
	init->e = 0;
	init->player.x = 0;
	init->player.y = 0;

}*/

void	ft_initialise(t_data *init, int fd)
{
	init->map->map = get_next_line(fd);
	init->map->x = 0;
	init->map->y = 0;
}

int	main(int ac, char **av)
{
	t_data	init;
	int		fd;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if (fd < 0)
			return (ft_printf("Erreur de fichier\n"));
		if (ft_verification_fichier(&init, av) == 0)
			return (ft_printf("Erreur de nom de fichier\n"));
		init.mlx_ptr = mlx_init();
		if (!init.mlx_ptr)
			return (1);
		ft_initialise(&init, fd);
		ft_verification(&init);
		mlx_new_window(init.win_ptr, 800, 1200, "so_long");
		mlx_key_hook(init.mlx_ptr, ft_touche(), &init);
		/*mlx_hook(init.mlx_ptr, KeyRelease, KeyReleaseMask, ft_touche(&init), ); a voir le quelle est le meilleure entre mlx_key_hook et mlx_hook*/
		mlx_loop(init.mlx_ptr);
	}
	else
		ft_printf("Erreur, mauvais nombre d'argument");
}
