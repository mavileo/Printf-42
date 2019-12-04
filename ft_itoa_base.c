/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:08:09 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/04 21:19:56 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_len(long nb, int len_base)
{
	int count;

	count = 0;
	while (nb)
	{
		nb = nb / len_base;
		count++;
	}
	return (count);
}

char	*ft_divmod(long nb, char *base, int len_base, int neg)
{
	char	*res;
	int		len;
	int		mod;

	len = ft_len(nb, len_base) + neg;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (neg)
		res[0] = '-';
	res[len] = 0;
	len--;
	mod = 0;
	while (nb)
	{
		mod = nb % len_base;
		res[len] = base[mod];
		nb = nb / len_base;
		len--;
	}
	return (res);
}

char	*ft_itoa_base(long nb, char *base)
{
	int		len_base;
	int		neg;

	neg = 0;
	len_base = ft_strlen(base);
	if (base == NULL)
		return (NULL);
	if (nb == 0)
		return (ft_strdup("0"));
	if (nb < 0)
	{
		neg = 1;
		ft_itoa_base(-nb, base);
	}
	return (ft_divmod(nb, base, len_base, neg));
}
