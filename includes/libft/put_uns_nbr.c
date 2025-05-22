/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_uns_nbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: llupache <llupache@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/01 19:12:28 by llupache          #+#    #+#             */
/*   Updated: 2025/02/22 19:46:50 by llupache         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	cycle_uns(unsigned int nb, int count)
{
	char	number;

	if (nb != 0)
	{
		count = cycle_uns(nb / 10, count + 1);
		number = (nb % 10) + '0';
		write(1, &number, 1);
	}
	return (count);
}

int	ft_put_uns_nbr(unsigned int nb, int count)
{
	if (nb < 0)
	{
		nb = -nb;
		write(1, "-", 1);
		count++;
	}
	else if (nb == 0)
	{
		write(1, "0", 1);
		count++;
		return (count);
	}
	count = cycle_uns(nb, count);
	return (count);
}
