/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 02:57:45 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/05 02:58:15 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_lstclear(t_list **lst)
{
	t_list *tmp;
	t_list *next;

	tmp = *lst;
	while (tmp)
	{
		next = tmp->next;
		free(tmp);
		tmp = next;
	}
	*lst = NULL;
}
