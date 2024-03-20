/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:50:52 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/18 10:56:26 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	game_destroy(t_data *data)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		mlx_destroy_image(data->mlx_ptr, data->texture->player_l[i]);
		mlx_destroy_image(data->mlx_ptr, data->texture->player_r[i]);
		mlx_destroy_image(data->mlx_ptr, data->texture->monster_l[i]);
		mlx_destroy_image(data->mlx_ptr, data->texture->monster_r[i]);
		mlx_destroy_image(data->mlx_ptr, data->texture->collect[i]);
		i++;
	}
	mlx_destroy_image(data->mlx_ptr, data->texture->exit[0]);
	mlx_destroy_image(data->mlx_ptr, data->texture->exit[1]);
	mlx_destroy_image(data->mlx_ptr, data->texture->wall);
	mlx_destroy_image(data->mlx_ptr, data->texture->floor);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	mlx_destroy_display(data->mlx_ptr);
	free(data->mlx_ptr);
	free_game(data);
	exit(0);
	return (0);
}

int	on_keypress(int keysym, t_data *data)
{
	key_event(keysym, data);
	return (0);
}

int	refresh(t_data *data)
{
	if (data->player->score == data->map->c_count)
	{
		data->player->win = 1;
	}
	draw_map(data, data->map, data->texture);
	data->texture->keyframe = (data->texture->keyframe + 1) % 4;
	if (data->texture->keyframe == 0)
	{
		data->texture->frame = (data->texture->frame + 1) % 4;
	}
	usleep(1000000 / FRAME_RATE);
	monster_logic(data);
	return (0);
}

void	key_event(int keysym, t_data *data)
{
	if (keysym == KEY_ESC)
		game_destroy(data);
	else if (keysym == KEY_W || keysym == KEY_UP)
		move_up(data);
	else if (keysym == KEY_S || keysym == KEY_DOWN)
		move_down(data);
	else if (keysym == KEY_A || keysym == KEY_LEFT)
		move_left(data);
	else if (keysym == KEY_D || keysym == KEY_RIGHT)
		move_right(data);
	else
		return ;
}