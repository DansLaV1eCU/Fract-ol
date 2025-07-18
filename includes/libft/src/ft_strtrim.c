/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 20:29:28 by llupache          #+#    #+#             */
/*   Updated: 2025/07/17 20:28:59 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isinset(char ch, const char *set)
{
	char	*new;

	new = (char *)set;
	while (*new)
	{
		if (ch == *new)
			return (1);
		new ++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		len;
	char	*news1;
	char	*res;

	news1 = (char *)s1;
	start = 0;
	while (news1[start] && isinset(news1[start], set))
		start++;
	len = ft_strlen(s1);
	while (isinset(news1[len - 1], set) && len > start)
		len--;
	res = ft_substr(s1, (unsigned int)start, (size_t)(len - start));
	return (res);
}
