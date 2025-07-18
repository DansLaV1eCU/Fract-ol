/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/12 12:59:43 by llupache          #+#    #+#             */
/*   Updated: 2025/07/17 20:28:48 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	count1;
	size_t	count2;
	char	*str1;
	char	*to_find1;

	str1 = (char *)str;
	to_find1 = (char *)to_find;
	if (to_find1[0] == '\0')
		return (str1);
	count1 = 0;
	while (str1[count1] && count1 < n)
	{
		count2 = 0;
		while (str1[count1 + count2] == to_find1[count2] && count1 + count2 < n
			&& to_find1[count2])
			count2++;
		if (!to_find1[count2])
			return (&str1[count1]);
		count1++;
	}
	return (NULL);
}
