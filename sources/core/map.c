/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:15:06 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/18 11:15:07 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	draw_objects(t_data *data, t_map *c, t_texture *t)
{
	if (c->map[c->row][c->col] == '1')
		render_image(data, t->wall, c);
	else if (c->map[c->row][c->col] == '0')
		render_image(data, t->floor, c);
	else if (c->map[c->row][c->col] == 'E')
		render_image(data, t->exit[data->player->win], c);
	else if (c->map[c->row][c->col] == 'C')
		render_image(data, t->collect[t->frame], c);
	else if (c->map[c->row][c->col] == 'P')
	{
		if (data->player->facing == 'L')
			render_image(data, t->player_l[t->frame], c);
		else if (data->player->facing == 'R')
			render_image(data, t->player_r[t->frame], c);
	}
	else if (c->map[c->row][c->col] == 'M')
	{
		if (data->monster->facing[data->monster->count] == 'L')
			render_image(data, t->monster_l[t->frame], c);
		else if (data->monster->facing[data->monster->count] == 'R')
			render_image(data, t->monster_r[t->frame], c);
		data->monster->count++;
	}
}

void	draw_map(t_data *data, t_map *c, t_texture *t)
{
	c->row = 0;
	data->monster->count = 0;
	while (c->row < c->current_line)
	{
		c->col = 0;
		while (c->col < c->len)
		{
			draw_objects(data, c, t);
			c->col++;
		}
		c->row++;
	}
	render_moves(data, c);
}

void	map_window(t_data *data, t_map *c, t_texture *t)
{
	c->width = SIZE * c->len;
	c->height = SIZE * c->current_line;
	data->mlx_ptr = mlx_init();
	data->win_ptr = mlx_new_window(data->mlx_ptr,
			c->width, c->height, "so_long");
	render_xpm(data, t);
	mem_monster(data);
	draw_map(data, c, t);
	return ;
}

void	create_map(t_data *data, int argc, char **argv)
{
	init_vars(data);
	if (open_ber(data->map, argv[1], argc, argv) != -1
		&& validate_path(data->map, data->player, data->map->fd) == true)
	{
		map_window(data, data->map, data->texture);
		game_loop(data);
	}
	close(data->map->fd);
}