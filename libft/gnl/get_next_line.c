/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 21:59:16 by jergoh            #+#    #+#             */
/*   Updated: 2024/06/08 21:59:17 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

void	prepare_list_from_file(int fd, t_list **list)
{
	char	*buffer;
	int		num_bytes;

	num_bytes = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (!found_newline(*list) && num_bytes != 0)
	{
		if (buffer == NULL)
			return ;
		num_bytes = read(fd, buffer, BUFFER_SIZE);
		if ((*list == NULL && num_bytes == 0) || num_bytes == -1)
		{
			free(buffer);
			if (num_bytes == -1)
				free_list(*list);
			*list = NULL;
			return ;
		}
		buffer[num_bytes] = '\0';
		append_buffer_to_list(list, buffer, num_bytes);
	}
	free(buffer);
}

void	append_buffer_to_list(t_list **list, char *buffer, int num_bytes)
{
	int		i;
	t_list	*last;
	t_list	*new_node;

	new_node = malloc(sizeof(t_list));
	new_node->content = malloc(sizeof(char) * (num_bytes + 1));
	if (new_node == NULL
		|| new_node->content == NULL)
		return ;
	new_node->next = NULL;
	i = 0;
	while (buffer[i] && i < num_bytes)
	{
		new_node->content[i] = buffer[i];
		i++;
	}
	new_node->content[i] = '\0';
	if (*list == NULL)
		*list = new_node;
	else
	{
		last = ft_lstlast(*list);
		last->next = new_node;
	}
}

void	read_line_from_list(t_list *list, char **line)
{
	int	i;
	int	j;

	if (list == NULL)
		return ;
	prepare_line(line, list);
	if (*line == NULL)
		return ;
	j = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				(*line)[j++] = list->content[i];
				break ;
			}
			(*line)[j++] = list->content[i++];
		}
		list = list->next;
	}
	(*line)[j] = '\0';
}

t_list	*remove_last_element(t_list **lst)
{
	t_list	*last;
	t_list	*clean_node;
	int		i;

	clean_node = malloc(sizeof(t_list));
	if (lst == NULL || clean_node == NULL)
	{
		*lst = clean_node;
		return (NULL);
	}
	clean_node->next = NULL;
	last = ft_lstlast(*lst);
	i = 0;
	while (last->content[i] && last->content[i] != '\n')
		i++;
	if (last->content[i] == '\n')
		i++;
	clean_node->content = remove_last_element_extra(last, i);
	if (clean_node->content == NULL)
		return (NULL);
	free_list(*lst);
	*lst = clean_node;
	return (clean_node);
}

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	prepare_list_from_file(fd, &list);
	if (list == NULL)
		return (NULL);
	read_line_from_list(list, &line);
	remove_last_element(&list);
	if (line[0] == '\0')
	{
		free_list(list);
		list = NULL;
		free(line);
		return (NULL);
	}
	return (line);
}
