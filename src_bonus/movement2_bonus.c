/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 19:14:34 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/26 13:28:50 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	up_mover(t_data *info)
{
	info->moves++;
	ft_printf("Moves: %d\n", info->moves);
	info->image.player_r->instances[0].y -= 1;
	info->image.player_u->instances[0].y -= 1;
	info->image.player_l->instances[0].y -= 1;
	info->image.player_d->instances[0].y -= 1;
}

static void	down_mover(t_data *info)
{
	info->moves++;
	ft_printf("Moves: %d\n", info->moves);
	info->image.player_r->instances[0].y += 1;
	info->image.player_u->instances[0].y += 1;
	info->image.player_l->instances[0].y += 1;
	info->image.player_d->instances[0].y += 1;
}

static void	left_mover(t_data *info)
{
	info->moves++;
	ft_printf("Moves: %d\n", info->moves);
	info->image.player_r->instances[0].x -= 1;
	info->image.player_u->instances[0].x -= 1;
	info->image.player_l->instances[0].x -= 1;
	info->image.player_d->instances[0].x -= 1;
}

static void	right_mover(t_data *info)
{
	info->moves++;
	ft_printf("Moves: %d\n", info->moves);
	info->image.player_r->instances[0].x += 1;
	info->image.player_u->instances[0].x += 1;
	info->image.player_l->instances[0].x += 1;
	info->image.player_d->instances[0].x += 1;
}

void	images_mover(int dir, t_data *info)
{
	int	cont;

	cont = 0;
	if (dir == 0)
		up_mover(info);
	else if (dir == 1)
		down_mover(info);
	else if (dir == 2)
		left_mover(info);
	else if (dir == 3)
		right_mover(info);
}
