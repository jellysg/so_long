/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:53 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:26:53 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int	count;

	count = 0;
	while (str[count])
		count++;
	while (count >= 0)
	{
		if (str[count] == (char)c)
			return ((char *)(str + count));
		count--;
	}
	return (0);
}
