/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:18:44 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/01 16:30:29 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strdup(const char *s)
{
	char	*res;
	int		count;

	count = 0;
	if (!(res = malloc(sizeof(*s) * (ft_strlen(s) + 1))))
		return (NULL);
	while (s[count])
	{
		res[count] = s[count];
		count++;
	}
	res[count] = 0;
	return (res);
}
