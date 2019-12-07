/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_which_type.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 01:36:32 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/06 22:00:52 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_which_type(t_list *list, va_list va_lst)
{
	int		prec_param;

	prec_param = 0;
	if (list->par_width)
		list->width = va_arg(va_lst, int);
	if (list->par_prec)
		list->prec_len = va_arg(va_lst, int);
	if (list->type == 'd' || list->type == 'i')
		ft_print_nb(va_arg(va_lst, int), list);
	else if (list->type == 'c')
		ft_print_c(va_arg(va_lst, int), list);
	else if (list->type == 's')
		ft_print_s(va_arg(va_lst, char *), list);
	else if (list->type == 'x' || list->type == 'X')
		ft_print_x(va_arg(va_lst, unsigned int), list);
	else if (list->type == 'p')
		ft_print_p(va_arg(va_lst, void *), list);
	else if (list->type == 'u')
		ft_print_u(va_arg(va_lst, unsigned int), list);
	else if (list->type == '%')
		ft_print_pc('%', list);
}
