/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:31:02 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/18 11:31:03 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	move_up(t_data *data)
{
	if (data->map->map[data->player->y][data->player->x] == 'X')
		data->map->map[data->player->y][data->player->x] = 'E';
    else
		data->map->map[data->player->y][data->player->x] = '0';
	check_up(data);
	if (data->map->map[data->player->y][data->player->x] == 'E')
		data->map->map[data->player->y][data->player->x] = 'X';
    else
		data->map->map[data->player->y][data->player->x] = 'P';
}

void	move_down(t_data *data)
{
	if (data->map->map[data->player->y][data->player->x] == 'X')
		data->map->map[data->player->y][data->player->x] = 'E';
    else
		data->map->map[data->player->y][data->player->x] = '0';
	check_down(data);
	if (data->map->map[data->player->y][data->player->x] == 'E')
		data->map->map[data->player->y][data->player->x] = 'X';
    else
		data->map->map[data->player->y][data->player->x] = 'P';
}

void	move_left(t_data *data)
{
	if (data->map->map[data->player->y][data->player->x] == 'X')
		data->map->map[data->player->y][data->player->x] = 'E';
    else
		data->map->map[data->player->y][data->player->x] = '0';
	check_left(data);
	if (data->map->map[data->player->y][data->player->x] == 'E')
		data->map->map[data->player->y][data->player->x] = 'X';
    else
		data->map->map[data->player->y][data->player->x] = 'P';
}

void	move_right(t_data *data)
{
	if (data->map->map[data->player->y][data->player->x] == 'X')
		data->map->map[data->player->y][data->player->x] = 'E';
    else
		data->map->map[data->player->y][data->player->x] = '0';
	check_right(data);
	if (data->map->map[data->player->y][data->player->x] == 'E')
		data->map->map[data->player->y][data->player->x] = 'X';
    else
		data->map->map[data->player->y][data->player->x] = 'P';
}