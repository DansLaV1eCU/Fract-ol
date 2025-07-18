/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danslav1e <danslav1e@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/20 13:33:30 by llupache          #+#    #+#             */
/*   Updated: 2025/07/17 20:27:57 by danslav1e        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	long	length;
	char	*ptr;
	char	*src1;
	int		count;

	length = ft_strlen(src);
	src1 = (char *)src;
	ptr = (char *)malloc((length + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	count = 0;
	while (src1[count])
	{
		ptr[count] = src1[count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}
