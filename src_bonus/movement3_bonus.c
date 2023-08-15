/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 12:27:05 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 12:56:57 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	moving_enemy(int i, t_data *info)
{
	if (info->enemydir[i] == 0)
		move_en_up(i, info);
	else if (info->enemydir[i] == 1)
		move_en_down(i, info);
	else if (info->enemydir[i] == 2)
		move_en_left(i, info);
	else if (info->enemydir[i] == 3)
		move_en_right(i, info);
}

void	move_enemy(int i, t_data *info)
{
	if (!en_movechecker(i, info))
	{
		srand(time(NULL));
		info->enemydir[i] = rand() % 4;
		return ;
	}
	moving_enemy(i, info);
}
