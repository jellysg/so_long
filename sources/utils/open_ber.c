/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_ber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 11:42:15 by jergoh            #+#    #+#             */
/*   Updated: 2024/03/18 11:42:16 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	object_tracker(t_map *c)
{
	if (c->check == 'E')
		c->e_count++;
	if (c->check == 'P')
		c->p_count++;
	if (c->check == 'C')
		c->c_count++;
	if (c->check == 'M')
		c->m_count++;
	if (c->check != 'E' && c->check != 'P' && c->check != 'C'
		&& c->check != '1' && c->check != '0' && c->check != 'M')
	{
		c->fd = -2;
		return (-1);
	}
	return (0);
}

int	walls_and_components(t_map *c)
{
	if (c->line[c->len] == '\n')
		c->line[c->len] = '\0';
	if (c->len != ft_strlen(c->line))
		return (-1);
	if (c->line[c->current_col] != '1' || c->line[c->len - 1] != '1')
	{
		c->fd = -1;
		return (-1);
	}
	while (c->current_col < c->len)
	{
		c->check = c->line[c->current_col];
		if (object_tracker(c) == -1)
			return (-1);
		c->current_col++;
	}
	return (0);
}

int	valid_map_format(t_map *c)
{
	if (c->line[0] == '\n')
		return (-1);
	if (c->current_line == 0)
	{
		boundary_check(c);
	}
	else
	{
		if (walls_and_components(c) != 0)
		{
			c->fd = -1;
			return (-1);
		}
	}
	mem_alloc(c);
	c->current_line++;
	c->current_col = 0;
	free(c->prev_line);
	c->prev_line = ft_strdup(c->line);
	return (0);
}

void	read_ber(t_map *c)
{
	c->line = "";
	while (c->line)
	{
		c->line = get_next_line(c->fd);
		if (c->line != NULL)
		{
			if (valid_map_format(c) != 0)
			{
				invalid_format(c);
				free(c->line);
				return ;
			}
			free(c->line);
		}
	}
	while (c->current_col < c->len)
	{
		if (c->prev_line[c->current_col] != '1')
		{
			invalid_format(c);
			break ;
		}
		c->current_col++;
	}
	if (c->e_count != 1 || c->p_count != 1 || c->c_count < 1)
		invalid_format(c);
}

int	open_ber(t_map *c, char *map_name, int ac, char **av)
{
	if (ac != 2 || ft_strncmp(av[1] + ft_strlen(av[1]) - 4, ".ber", 4) != 0)
	{
		printf("Invalid arguments.\n");
		return (1);
	}
	c->fd = open(map_name, O_RDONLY);
	if (c->fd == -1)
	{
		perror("Error opening file.\n");
		return (1);
	}
	read_ber(c);
	return (c->fd);
}