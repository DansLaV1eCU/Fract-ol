/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:00:16 by llupache          #+#    #+#             */
/*   Updated: 2025/07/17 20:28:53 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int search_str)
{
	unsigned char	*new;
	int				count;

	count = ft_strlen(str);
	new = (unsigned char *)str;
	while (count != -1)
	{
		if (new[count] == (unsigned char)search_str)
			return ((char *)&new[count]);
		count--;
	}
	return (NULL);
}
