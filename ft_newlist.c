/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_newlist.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/01 20:19:30 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/07 00:41:58 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_newlist(int nb)
{
	t_list	*elem;
	t_list	*res;

	res = NULL;
	while (nb >= 0)
	{
		if (!(elem = malloc(sizeof(t_list))))
			return (NULL);
		elem->left = 0;
		elem->prec = 0;
		elem->par_prec = 0;
		elem->par_width = 0;
		elem->prec_len = 0;
		elem->width = 0;
		elem->fillzer = 0;
		elem->type = 0;
		elem->next = res;
		res = elem;
		nb--;
	}
	return (res);
}
