/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:36:32 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 04:36:48 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_which_type(t_list *list, va_list va_lst)
{
	int		prec_param;

	prec_param = 0;
	if (list->par_len)
		prec_param = va_arg(va_lst, int);
	if (list->type == 'c')
		ft_print_c(va_arg(va_lst, int), list, prec_param);
	else if (list->type == 's')
		ft_print_s(va_arg(va_lst, char *), list, prec_param);
	else if (list->type == 'd' || list->type == 'i')
		ft_print_nb(va_arg(va_lst, int), list, prec_param);
	else if (list->type == 'p')
		ft_print_p(va_arg(va_lst, void *), list, prec_param);
	else if (list->type == 'x' || list->type == 'X')
		ft_print_x(va_arg(va_lst, unsigned int), list, prec_param, list->type);
	else if (list->type == 'u')
		ft_print_u(va_arg(va_lst, unsigned int), list, prec_param);
}
