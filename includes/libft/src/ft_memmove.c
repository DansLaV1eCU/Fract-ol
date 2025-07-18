/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/19 18:06:09 by llupache          #+#    #+#             */
/*   Updated: 2025/07/17 20:27:10 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest_str, const void *src_str, size_t n)
{
	unsigned char	*new_src;
	unsigned char	*new_dest;

	if (!dest_str && !src_str && n > 0)
		return (NULL);
	new_dest = (unsigned char *)dest_str;
	new_src = (unsigned char *)src_str;
	if (dest_str > src_str)
	{
		while (n--)
		{
			new_dest[n] = new_src[n];
		}
		return (dest_str);
	}
	else
	{
		return (ft_memcpy(dest_str, src_str, n));
	}
}
