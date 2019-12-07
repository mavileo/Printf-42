/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 19:30:09 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/07 00:41:07 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_substr(char const *s, int start, int len)
{
	char	*res;
	int		count;

	if (!s || len < 1 || len > 2147483647)
		return (ft_strdup(""));
	if (start > ft_strlen(s))
		return (ft_strdup(""));
	count = 0;
	if (!(res = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (count < len)
		res[count++] = s[start++];
	res[count] = 0;
	return (res);
}
