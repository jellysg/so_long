/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/08 22:00:04 by jergoh            #+#    #+#             */
/*   Updated: 2024/06/08 22:00:05 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../includes/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

char	*remove_last_element_extra(t_list *last, int i)
{
	int		j;
	int		len;
	char	*trimmed;

	len = 0;
	while (last->content[len])
		len++;
	trimmed = malloc(sizeof(char) * (len - i + 1));
	if (trimmed == NULL)
		return (NULL);
	j = 0;
	while (last->content[i])
		trimmed[j++] = last->content[i++];
	trimmed[j] = '\0';
	return (trimmed);
}

bool	found_newline(t_list *list)
{
	int		i;

	if (list == NULL)
		return (false);
	i = 0;
	if (list == NULL)
		return (false);
	while (list->next != NULL)
		list = list->next;
	while (list->content[i])
	{
		if (list->content[i] == '\n')
			return (true);
		i++;
	}
	return (false);
}

void	prepare_line(char **line, t_list *list)
{
	int	i;
	int	len;

	len = 0;
	while (list)
	{
		i = 0;
		while (list->content[i])
		{
			if (list->content[i] == '\n')
			{
				len++;
				break ;
			}
			len++;
			i++;
		}
		list = list->next;
	}
	*line = malloc(sizeof(char) * (len + 1));
}

void	free_list(t_list *list)
{
	t_list	*current;
	t_list	*next;

	current = list;
	while (current)
	{
		free(current->content);
		next = current->next;
		free(current);
		current = next;
	}
}
