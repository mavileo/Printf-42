/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:53:49 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/04 15:41:11 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_int_min(void)
{
	ft_putchar('-', 0);
	ft_putchar('2', 0);
	ft_putnbr(147483648);
}

void	ft_putnbr(long nb)
{
	if (nb == -9999999999)
		print_int_min();
	else
	{
		if (nb < 10 && nb > -1)
			ft_putchar(nb + 48, 0);
		else if (nb < 0)
		{
			ft_putchar('-', 0);
			ft_putnbr(nb * (-1));
		}
		else
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
	}
}
