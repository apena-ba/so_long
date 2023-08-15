/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collisions_applier1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/23 18:25:59 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/27 22:16:10 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	collision_apply(int pos, t_data *info)
{
	if (pos == -1)
		return ;
	if (info->image.coin->instances[pos].enabled == true)
	{
		info->image.coin->instances[pos].enabled = false;
		info->map_info.coins--;
	}
}

void	ft_exit_success(t_data *info)
{
	ft_printf("\033[0;32mYOU WIN!!\033[0m\n");
	ft_free_charpp(info->map_info.map_data);
	free(info->enemydir);
	usleep(500000);
	exit(1);
}

void	ft_exit_failure(t_data *info)
{
	ft_printf("\033[0;31mYOU LOST!!\033[0m\n");
	ft_free_charpp(info->map_info.map_data);
	free(info->enemydir);
	usleep(500000);
	exit(1);
}
