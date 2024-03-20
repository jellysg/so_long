/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logic.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:01:18 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/18 11:01:21 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	check_unique(t_data *data)
{
	if (data->map->map[data->player->y][data->player->x] == 'C')
	{
		data->player->score++;
	}
	else if (data->map->map[data->player->y][data->player->x] == 'M')
	{
		ft_printf("You lost!\n");
		game_destroy(data);
	}
	return ;
}

void	check_up(t_data *data)
{
	if (data->map->map[data->player->y - 1][data->player->x] == '1')
		return ;
	else if (data->map->map[data->player->y - 1][data->player->x] == 'E')
	{
		if (data->player->win == 1)
		{
			ft_printf("You won!\n");
			game_destroy(data);
		}
		return ;
	}
	else
	{
		data->player->y--;
		data->player->moves++;
		check_unique(data);
	}
	return ;
}

void	check_down(t_data *data)
{
	if (data->map->map[data->player->y + 1][data->player->x] == '1')
		return ;
	else if (data->map->map[data->player->y + 1][data->player->x] == 'E')
	{
		if (data->player->win == 1)
		{
			ft_printf("You won!\n");
			game_destroy(data);
		}
		return ;
	}
	else
	{
		data->player->y++;
		data->player->moves++;
		check_unique(data);
	}
	return ;
}

void	check_left(t_data *data)
{
	data->player->facing = 'L';
	if (data->map->map[data->player->y][data->player->x - 1] == '1')
		return ;
	else if (data->map->map[data->player->y][data->player->x - 1] == 'E')
	{
		if (data->player->win == 1)
		{
			ft_printf("You won!\n");
			game_destroy(data);
		}
		return ;
	}
	else
	{
		data->player->x--;
		data->player->moves++;
		check_unique(data);
	}
	return ;
}

void	check_right(t_data *data)
{
	data->player->facing = 'R';
	if (data->map->map[data->player->y][data->player->x + 1] == '1')
		return ;
	else if (data->map->map[data->player->y][data->player->x + 1] == 'E')
	{
		if (data->player->win == 1)
		{
			ft_printf("You won!\n");
			game_destroy(data);
		}
		return ;
	}
	else
	{
		data->player->x++;
		data->player->moves++;
		check_unique(data);
	}
	return ;
}