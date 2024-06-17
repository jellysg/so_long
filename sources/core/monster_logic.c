/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monster_logic.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:27:00 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/18 11:27:01 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	monster_left(t_data *data, int num)
{
	char	co;

	co = data->map->map[data->monster->y[num]][data->monster->x[num] - 1];
	if (co == '1' || co == 'E' || co == 'C' || co == 'M' || co == 'X')
	{
		data->monster->facing[num] = 'R';
	}
	else if (co == 'P')
	{
		ft_printf("You lost!\n");
		game_destroy(data);
	}
	else
	{
		data->map->map[data->monster->y[num]][data->monster->x[num]] = '0';
		data->monster->x[num]--;
		data->map->map[data->monster->y[num]][data->monster->x[num]] = 'M';
	}
}

void	monster_right(t_data *data, int num)
{
	char	co;

	co = data->map->map[data->monster->y[num]][data->monster->x[num] + 1];
	if (co == '1' || co == 'E' || co == 'C' || co == 'M' || co == 'X')
	{
		data->monster->facing[num] = 'L';
	}
	else if (co == 'P')
	{
		ft_printf("You lost!\n");
		game_destroy(data);
	}
	else
	{
		data->map->map[data->monster->y[num]][data->monster->x[num]] = '0';
		data->monster->x[num]++;
		data->map->map[data->monster->y[num]][data->monster->x[num]] = 'M';
	}
}

void	monster_move(t_data *data)
{
	int	num;

	num = 0;
	data->monster->idle_time = (data->monster->idle_time + 1) % 60;
	while (num < data->map->m_count)
	{
		if (data->monster->idle_time == 0)
		{
			if (data->monster->facing[num] == 'L')
			{
				monster_left(data, num);
			}
			else if (data->monster->facing[num] == 'R')
			{
				monster_right(data, num);
			}
		}
		num++;
	}
}

void	monster_logic(t_data *data)
{
	init_monster_coords(data->map, data->monster);
	monster_move(data);
}
