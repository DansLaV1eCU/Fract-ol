/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 19:18:08 by llupache          #+#    #+#             */
/*   Updated: 2025/07/17 20:29:05 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t			count;
	unsigned int	start1;
	char			*substr;

	if (!s)
		return (NULL);
	if (start >= (unsigned int)ft_strlen(s))
		return (ft_strdup(""));
	start1 = start;
	count = 0;
	while (s[start1++] && count < len)
		count++;
	substr = (char *)malloc(count * sizeof(char) + 1);
	if (!substr)
		return (NULL);
	count = 0;
	while (count < len && s[count])
	{
		substr[count] = s[start];
		start++;
		count++;
	}
	substr[count] = '\0';
	return (substr);
}
