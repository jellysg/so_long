/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:48 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:26:49 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

#include <string.h>

char	*ft_strnstr(const char *string, const char *find, size_t n)
{
	size_t	counter;
	size_t	match;

	counter = 0;
	match = 0;
	if (find[0] == '\0')
		return ((char *)string);
	while (string[counter] != '\0' && counter < n)
	{
		while (string[counter + match] == find[match] && counter + match < n)
		{
			if (find[match + 1] == '\0')
				return ((char *)(string + counter));
			match++;
		}
		match = 0;
		counter++;
	}
	return (NULL);
}
