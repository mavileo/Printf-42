/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsign.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 21:53:49 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 04:40:07 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putunsign(unsigned int nb)
{
	if (nb < 10 && nb >= 0)
		ft_putchar(nb + 48, 0);
	else
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
}
