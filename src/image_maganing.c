/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_maganing.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 16:49:39 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/28 09:48:59 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	image_secondcreator(t_data *info)
{
	mlx_texture_t	*texture;

	texture = mlx_load_png("./pngs/open4_exit.png");
	info->image.exit_open = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/player_right.png");
	info->image.player_r = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/player_left.png");
	info->image.player_l = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/player_up.png");
	info->image.player_u = mlx_texture_to_image(info->mlx, texture);
	mlx_delete_texture(texture);
	texture = mlx_load_png("./pngs/player_down.png");
	info->image.player_d = mlx_texture_to_image(info->mlx, texture);
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
}
