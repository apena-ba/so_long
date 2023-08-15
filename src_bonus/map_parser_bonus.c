/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parser.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apena-ba <apena-ba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/17 23:02:43 by apena-ba          #+#    #+#             */
/*   Updated: 2022/09/26 20:39:23 by apena-ba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static int	lenght_map_checker(char **map_holder, t_map *info, char *mapstr)
{
	int		i;
	int		x;
	char	*cmp;

	cmp = ".ber";
	i = 0;
	while (i < info->linebreaks - 1)
	{
		if ((ft_strlen(map_holder[i]) != ft_strlen(map_holder[i + 1]))
			|| !map_holder[info->linebreaks])
			return (0);
		i++;
	}
	if (ft_strlen(map_holder[i]) != ft_strlen(map_holder[i + 1]) + 1)
		return (0);
	i = 0;
	x = 0;
	while (mapstr[i] && mapstr[i] != '.')
		i++;
	while (cmp[x] || mapstr[i])
	{
		if (mapstr[i++] != cmp[x++])
			return (0);
	}
	return (1);
}

static int	info_map_counter(int fd, t_map *info)
{
	int	i;

	i = 0;
	info->player = 0;
	info->linebreaks = 0;
	info->coins = 0;
	info->exit = 0;
	while (1)
	{
		if (read(fd, &info->buffer, 1) == 0)
			break ;
		else if (info->buffer == '\n')
			info->linebreaks++;
		else if (info->buffer == 'P')
			info->player++;
		else if (info->buffer == 'C')
			info->coins++;
		else if (info->buffer == 'E')
			info->exit++;
		else if (info->buffer == 'X')
			info->enemy++;
		else if (info->buffer != '0' && info->buffer != '1')
			return (0);
	}
	return (1);
}

static int	top_bottom_checker(char **map_holder, t_map *info)
{
	int	i;

	i = 0;
	while (map_holder[0][i] != '\n')
	{
		if (map_holder[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (map_holder[info->linebreaks][i] != '\0'
		&& map_holder[info->linebreaks][i] != '\n')
	{
		if (map_holder[info->linebreaks][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static char	**map_fuller(int fd, t_map *info)
{
	char	**res;
	int		i;

	i = 0;
	res = malloc(sizeof(char *) * (info->linebreaks + 2));
	res[i] = get_next_line(fd);
	while (res[i++])
		res[i] = get_next_line(fd);
	i = 0;
	return (res);
}

int	map_checker(int fd, char *mapstr, t_data *info)
{
	int	i;

	info->map_info.enemy = 0;
	if (!info_map_counter(fd, &info->map_info) || info->map_info.linebreaks < 2
		|| info->map_info.coins < 1 || info->map_info.exit < 1
		|| info->map_info.player != 1)
		return (0);
	close(fd);
	fd = open(mapstr, O_RDONLY);
	info->map_info.map_data = map_fuller(fd, &info->map_info);
	i = 0;
	if (!lenght_map_checker(info->map_info.map_data, &info->map_info, mapstr)
		|| !top_bottom_checker(info->map_info.map_data, &info->map_info))
		return (ft_free_charpp(info->map_info.map_data), 0);
	while (i < info->map_info.linebreaks)
	{
		if (info->map_info.map_data[i][0] != '1'
			|| info->map_info.map_data[i][ft_strlen(info->map_info.map_data[i])
			- 2] != '1')
			return (ft_free_charpp(info->map_info.map_data), 0);
		i++;
	}
	return (1);
}
