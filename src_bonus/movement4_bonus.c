/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:55:58 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 13:13:42 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	en_move_toimage(int i, int dir, t_data *info)
{
	info->image.enemy_u->instances[i].enabled = false;
	info->image.enemy_d->instances[i].enabled = false;
	info->image.enemy_l->instances[i].enabled = false;
	info->image.enemy_r->instances[i].enabled = false;
	if (dir == 0)
		info->image.enemy_u->instances[i].enabled = true;
	else if (dir == 1)
		info->image.enemy_d->instances[i].enabled = true;
	else if (dir == 2)
		info->image.enemy_l->instances[i].enabled = true;
	else if (dir == 3)
		info->image.enemy_r->instances[i].enabled = true;
}

void	move_en_up(int i, t_data *info)
{
	en_move_toimage(i, 0, info);
	info->image.enemy_r->instances[i].y -= 1;
	info->image.enemy_u->instances[i].y -= 1;
	info->image.enemy_l->instances[i].y -= 1;
	info->image.enemy_d->instances[i].y -= 1;
}

void	move_en_down(int i, t_data *info)
{
	en_move_toimage(i, 1, info);
	info->image.enemy_r->instances[i].y += 1;
	info->image.enemy_u->instances[i].y += 1;
	info->image.enemy_l->instances[i].y += 1;
	info->image.enemy_d->instances[i].y += 1;
}

void	move_en_left(int i, t_data *info)
{
	en_move_toimage(i, 2, info);
	info->image.enemy_r->instances[i].x -= 1;
	info->image.enemy_u->instances[i].x -= 1;
	info->image.enemy_l->instances[i].x -= 1;
	info->image.enemy_d->instances[i].x -= 1;
}

void	move_en_right(int i, t_data *info)
{
	en_move_toimage(i, 3, info);
	info->image.enemy_r->instances[i].x += 1;
	info->image.enemy_u->instances[i].x += 1;
	info->image.enemy_l->instances[i].x += 1;
	info->image.enemy_d->instances[i].x += 1;
}
