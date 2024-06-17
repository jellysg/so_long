/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:36:20 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/18 13:36:21 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_moves(t_data *d, t_map *c)
{
	char	*msg;
	char	*moves;

	moves = ft_itoa(d->player->moves);
	msg = ft_strjoin("Moves: ", moves);
	mlx_string_put(d->mlx_ptr, d->win_ptr, c->width / 2,
		c->height - c->current_line, 11001101, msg);
	free(msg);
	free(moves);
}

void	*xpm_i(t_data *d, char *path, t_texture *t)
{
	return (mlx_xpm_file_to_image(d->mlx_ptr, path, t->px_size, t->px_size));
}

void	render_characters(t_data *data, t_texture *t)
{
	t->player_l[0] = xpm_i(data, "./assets/player/idle_L_0.xpm", t);
	t->player_r[0] = xpm_i(data, "./assets/player/idle_R_0.xpm", t);
	t->player_l[1] = xpm_i(data, "./assets/player/idle_L_1.xpm", t);
	t->player_r[1] = xpm_i(data, "./assets/player/idle_R_1.xpm", t);
	t->player_l[2] = xpm_i(data, "./assets/player/idle_L_2.xpm", t);
	t->player_r[2] = xpm_i(data, "./assets/player/idle_R_2.xpm", t);
	t->player_l[3] = xpm_i(data, "./assets/player/idle_L_3.xpm", t);
	t->player_r[3] = xpm_i(data, "./assets/player/idle_R_3.xpm", t);
	t->monster_l[0] = xpm_i(data, "./assets/monster/idle_L_0.xpm", t);
	t->monster_r[0] = xpm_i(data, "./assets/monster/idle_R_0.xpm", t);
	t->monster_l[1] = xpm_i(data, "./assets/monster/idle_L_1.xpm", t);
	t->monster_r[1] = xpm_i(data, "./assets/monster/idle_R_1.xpm", t);
	t->monster_l[2] = xpm_i(data, "./assets/monster/idle_L_2.xpm", t);
	t->monster_r[2] = xpm_i(data, "./assets/monster/idle_R_2.xpm", t);
	t->monster_l[3] = xpm_i(data, "./assets/monster/idle_L_3.xpm", t);
	t->monster_r[3] = xpm_i(data, "./assets/monster/idle_R_3.xpm", t);
}

void	render_xpm(t_data *data, t_texture *t)
{
	t->px_size = malloc(sizeof(int));
	*t->px_size = SIZE;
	t->floor = xpm_i(data, "./assets/floor.xpm", t);
	t->wall = xpm_i(data, "./assets/wall.xpm", t);
	t->exit[0] = xpm_i(data, "./assets/exit/door_closed.xpm", t);
	t->exit[1] = xpm_i(data, "./assets/exit/door_open.xpm", t);
	t->collect[0] = xpm_i(data, "./assets/collect/coin_f0.xpm", t);
	t->collect[1] = xpm_i(data, "./assets/collect/coin_f1.xpm", t);
	t->collect[2] = xpm_i(data, "./assets/collect/coin_f2.xpm", t);
	t->collect[3] = xpm_i(data, "./assets/collect/coin_f3.xpm", t);
	render_characters(data, t);
	free(t->px_size);
}

void	render_image(t_data *d, void *img_ptr, t_map *c)
{
	int	x;
	int	y;

	x = c->col * SIZE;
	y = c->row * SIZE;
	mlx_put_image_to_window(d->mlx_ptr, d->win_ptr, img_ptr, x, y);
}
