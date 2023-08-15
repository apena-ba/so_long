/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   en_movechecker3.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 18:17:52 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 18:33:21 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	col_wp_up(int i, t_data *info)
{
	info->x_p = info->image.enemy_u->instances[i].x;
	info->y_p = info->image.enemy_u->instances[i].y - 2;
	info->x_e = info->image.player_u->instances[0].x;
	info->y_e = info->image.player_u->instances[0].y;
	if (((info->x_p >= info->x_e && info->x_p <= info->x_e) || (info->x_p
				+ 48 > info->x_e && info->x_p + 48 < info->x_e + 64))
		&& (info->y_p > info->y_e && info->y_p < info->y_e + 48))
		ft_exit_failure(info);
}

static void	col_wp_down(int i, t_data *info)
{
	info->x_p = info->image.enemy_u->instances[i].x;
	info->y_p = info->image.enemy_u->instances[i].y + 2 + 48;
	info->x_e = info->image.player_u->instances[0].x;
	info->y_e = info->image.player_u->instances[0].y;
	if (((info->x_p >= info->x_e && info->x_p <= info->x_e) || (info->x_p
				+ 48 > info->x_e && info->x_p + 48 < info->x_e + 64))
		&& (info->y_p > info->y_e && info->y_p < info->y_e + 48))
		ft_exit_failure(info);
}

static void	col_wp_left(int i, t_data *info)
{
	info->x_p = info->image.enemy_u->instances[i].x - 2;
	info->y_p = info->image.enemy_u->instances[i].y;
	info->x_e = info->image.player_u->instances[0].x;
	info->y_e = info->image.player_u->instances[0].y;
	if (((info->y_p >= info->y_e && info->y_p <= info->y_e) || (info->y_p
				+ 48 > info->y_e && info->y_p + 48 < info->y_e + 64))
		&& (info->x_p > info->x_e && info->x_p < info->x_e + 48))
		ft_exit_failure(info);
}

static void	col_wp_right(int i, t_data *info)
{
	info->x_p = info->image.enemy_u->instances[i].x + 2 + 48;
	info->y_p = info->image.enemy_u->instances[i].y;
	info->x_e = info->image.player_u->instances[0].x;
	info->y_e = info->image.player_u->instances[0].y;
	if (((info->y_p >= info->y_e && info->y_p <= info->y_e) || (info->y_p
				+ 48 > info->y_e && info->y_p + 48 < info->y_e + 64))
		&& (info->x_p > info->x_e && info->x_p < info->x_e + 48))
		ft_exit_failure(info);
}

void	col_w_player_checker(int dir, int i, t_data *info)
{
	if (dir == 0)
		col_wp_up(i, info);
	else if (dir == 1)
		col_wp_down(i, info);
	else if (dir == 2)
		col_wp_left(i, info);
	col_wp_right(i, info);
}
