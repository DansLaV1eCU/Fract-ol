/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/20 19:00:16 by llupache          #+#    #+#             */
/*   Updated: 2025/07/17 20:26:53 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int search_str, size_t n)
{
	unsigned char	*new;
	size_t			count;

	count = 0;
	new = (unsigned char *)str;
	while (count < n)
	{
		if (*new == (unsigned char)search_str)
			return ((void *)new);
		count++;
		new++;
	}
	return (NULL);
}
