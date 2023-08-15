/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 17:14:22 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 22:00:47 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "MLX42.h"
# include "libft.h"
# include <fcntl.h>
# include <memory.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>
# include <time.h>
# define WIDTH 1024
# define HEIGHT 1024

typedef struct s_map
{
	int				linebreaks;
	int				player;
	int				enemy;
	int				coins;
	int				exit;
	int				map_height;
	int				map_lenght;
	char			buffer;
	char			**map_data;
}					t_map;

typedef struct s_image
{
	mlx_image_t		*wall;
	mlx_image_t		*player_u;
	mlx_image_t		*player_d;
	mlx_image_t		*player_r;
	mlx_image_t		*player_l;
	mlx_image_t		*enemy_u;
	mlx_image_t		*enemy_d;
	mlx_image_t		*enemy_l;
	mlx_image_t		*enemy_r;
	mlx_image_t		*coin;
	mlx_image_t		*floor;
	mlx_image_t		*exit;
	mlx_image_t		*exit_nopen1;
	mlx_image_t		*exit_nopen2;
	mlx_image_t		*exit_nopen3;
	mlx_image_t		*exit_open;
}					t_image;

typedef struct s_data
{
	t_map			map_info;
	t_image			image;
	int				*enemydir;
	int				index;
	int				moves;
	int				x_p;
	int				y_p;
	int				x_e;
	int				y_e;
	int				x;
	int				y;
	int				coin_cont;
	int				coin_total;
	int				timer;
	int				ident;
	int				levitate;
	mlx_image_t		*moves_text;
	mlx_t			*mlx;
}					t_data;

int					map_checker(int fd, char *mapstr, t_data *info);
void				open_map(t_data *info);
void				image_creator(t_data *info);
void				door_drawer(t_data *info);
void				print_door(int cont, int x, int y, t_data *info);
int					movement_controller(int dir, t_data *info);
void				move_toimage(int dir, t_data *info);
int					collision_checker(int dir, t_data *info);
void				collision_apply(int pos, t_data *info);
void				images_mover(int dir, t_data *info);
void				exit_collision_checker(int dir, t_data *info);
void				ft_exit_success(t_data *info);
void				ft_exit_failure(t_data *info);
void				ft_time_manager(t_data *info);
void				init_animation(t_data *info);
void				enemy_collision_checker(int dir, t_data *info);
int					en_mleft_checker(int i, t_data *info);
int					en_mright_checker(int i, t_data *info);
int					en_movechecker(int i, t_data *info);
void				move_en_up(int i, t_data *info);
void				move_en_down(int i, t_data *info);
void				move_en_left(int i, t_data *info);
void				move_en_right(int i, t_data *info);
void				enemy_moving(t_data *info);
int					*en_dir_creator(t_data *info);
void				move_enemy(int i, t_data *info);
void				col_w_player_checker(int dir, int i, t_data *info);
void				ft_put_moves(t_data *info);
void				door_animation(t_data *info);

#endif
