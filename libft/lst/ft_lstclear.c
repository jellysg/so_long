/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:19:02 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:19:03 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*todelete;

	if (!lst)
		return ;
	while (*lst)
	{
		todelete = (*lst);
		*lst = (*lst)->next;
		ft_lstdelone(todelete, del);
	}
}
