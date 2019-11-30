/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 15:18:43 by mavileo           #+#    #+#             */
/*   Updated: 2019/11/30 17:25:31 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_list	*ft_lstnew(void)
{
	t_list	*lst;

	if (!(lst = malloc(sizeof(t_list))))
		return (NULL);
	lst->prec = 0;
	lst->len = 0;
	lst->fillzer = 0;
	lst->left = 0;
	lst->s = NULL;
	lst->p = NULL;
	lst->i = 0;
	lst->type = 0;
	lst->next = NULL;
	return (lst);
}
