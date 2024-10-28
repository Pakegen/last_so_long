/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: quenalla <quenalla@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/03 11:50:02 by qacjl             #+#    #+#             */
/*   Updated: 2024/10/28 14:24:48 by quenalla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../utils/libft/libft.h"
# include "../minilibx-linux/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

# define NOTHING "../texture/BACKGROUND.xpm"
# define WALL "../texture/WALL.xpm"
# define COLLECTIBLE "../texture/piece.xpm"
# define EXIT "../texture/flag.xpm"
# define START  "/../texture/slime_right.xpm"
# define PLAYER_LEFT "/../texture/slime_left.xpm"
# define PLAYER_RIGHT "/../texture/slime_right.xpm"
# define PLAYER_UP "/../texture/slime_up.xpm"
# define PLAYER_DOWN "/../texture/slime_down.xpm"


typedef struct s_map
{
	void	**map;
	char	*name;
	int		x;
	int		y;
}	t_map;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*player;
	void	*p_x;
	void	*p_y;
	char	*player_down;
	char	*player_left;
	char	*player_top;
	char	*player_right;
	t_map	*map;
}	t_data;



//INPUT
/*
# define KEY_W =
# define KEY_A =
# define KEY_S =
# define KEY_D =
# define ARROW_UP =
# define ARROW_LEFT =
# define ARROW_DOWN =
# define ARROW_RIGHT =
# define ESC = 65307
*/
//FOR THE MAP BER

# define WALL = 1
# define COLLECTIBLE = C
# define NOTHING = 0
# define START_POSITION = P
# define EXIT = E


//VERIFICATION MAP
int		ft_verification_fichier(t_data *init, char **av);
void	ft_verification(t_data *data);
void	ft_verification_lenght(t_data *data);
void	ft_verification_wall(t_data *data);
void	ft_verification_exit(t_data *data);
void	ft_verification_player(t_data *data);
void	ft_verification_collectible(t_data *data);

//INITIALISE
void	ft_initialise(t_data *init, int fd);

//EXIT
void	ft_exit(void);

#endif
