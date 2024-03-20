/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jergoh <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:26:01 by jergoh            #+#    #+#             */
/*   Updated: 2023/09/21 10:26:02 by jergoh           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static char	*ft_strcat(char const *s1, char const *s2, char *res)
{
	unsigned int	count;
	unsigned int	total;

	count = 0;
	total = 0;
	while (s1[count] != '\0')
	{
		res[total] = s1[count];
		count++;
		total++;
	}
	count = 0;
	while (s2[count] != '\0')
	{
		res[total] = s2[count];
		count++;
		total++;
	}
	res[total] = '\0';
	return (res);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*result;
	int		len1;
	int		len2;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen((char *)s1);
	len2 = ft_strlen((char *)s2);
	result = malloc((len1 + len2 + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	result = ft_strcat(s1, s2, result);
	return (result);
}
