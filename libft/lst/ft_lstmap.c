/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:19:34 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:19:35 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*result_list;
	t_list	*mapped_node;
	t_list	*temp;

	if (!f || !lst)
		return (NULL);
	result_list = NULL;
	while (lst)
	{
		temp = f(lst->content);
		mapped_node = ft_lstnew(temp);
		if (!mapped_node)
		{
			if (del && temp)
				del(temp);
			ft_lstclear(&result_list, del);
			return (NULL);
		}
		ft_lstadd_back(&result_list, mapped_node);
		lst = lst->next;
	}
	return (result_list);
}
