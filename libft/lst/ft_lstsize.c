/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:19:48 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:19:49 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*current_node;

	current_node = lst;
	count = 0;
	while (current_node != NULL)
	{
		count++;
		current_node = current_node->next;
	}
	return (count);
}
