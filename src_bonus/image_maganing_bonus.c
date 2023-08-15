/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_maganing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:49:39 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 21:29:41 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	image_thirdcreator(t_data *info)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./pngs/player_up.png");
	info->image.player_u = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/player_down.png");
	info->image.player_d = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/enemy_down.png");
	info->image.enemy_d = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/enemy_right.png");
	info->image.enemy_r = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/enemy_up.png");
	info->image.enemy_u = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/enemy_left.png");
	info->image.enemy_l = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
}

static void	image_secondcreator(t_data *info)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./pngs/open1_exit.png");
	info->image.exit_nopen1 = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/open2_exit.png");
	info->image.exit_nopen2 = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/open3_exit.png");
	info->image.exit_nopen3 = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/open4_exit.png");
	info->image.exit_open = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/player_right.png");
	info->image.player_r = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/player_left.png");
	info->image.player_l = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
}

void	image_creator(t_data *info)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./pngs/floor.png");
	info->image.floor = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/wall.png");
	info->image.wall = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/coin.png");
	info->image.coin = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/exit.png");
	info->image.exit = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	image_secondcreator(info);
	image_thirdcreator(info);
}

void	print_door(int cont, int x, int y, t_data *info)
{
	mlx_image_to_window(info->mlx, info->image.exit, x * 64, y * 64);
	info->image.exit->instances[cont].enabled = true;
	mlx_image_to_window(info->mlx, info->image.exit_open, x * 64, y * 64);
	info->image.exit_open->instances[cont].enabled = false;
	mlx_image_to_window(info->mlx, info->image.exit_nopen1, x * 64, y * 64);
	info->image.exit_nopen1->instances[cont].enabled = false;
	mlx_image_to_window(info->mlx, info->image.exit_nopen2, x * 64, y * 64);
	info->image.exit_nopen2->instances[cont].enabled = false;
	mlx_image_to_window(info->mlx, info->image.exit_nopen3, x * 64, y * 64);
	info->image.exit_nopen3->instances[cont].enabled = false;
}
