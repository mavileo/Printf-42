/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mavileo <mavileo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 05:42:35 by mavileo           #+#    #+#             */
/*   Updated: 2019/12/04 21:00:50 by mavileo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdint.h>
# include <inttypes.h>

typedef struct	s_list
{
	int				right;
	int				left;
	int				point;
	int				star_point;
	int				point_star;
	int				only_zer;
	int				prec_len;
	int				par_len;
	int				fillzer;
	void			*p;
	int				i;
	char			type;
	struct s_list	*next;
}				t_list;

int				ft_putchar(char c, int end);
void			ft_putnbr(long nb);
void			ft_putstr(char *str);
int				ft_isprint(int c);
int				ft_atoi(const char *nb);
int				ft_isdigit(int c);
char			*ft_strdup(const char *s);
int				ft_strlen(const char *s);
t_list			*ft_newlist(int nb);
int				ft_check_convers(char c);
int				ft_precision(const char *str, int i, t_list *stru);
void			ft_print_c(char c, t_list *list, int prec_len);
void			ft_print_s(char *s, t_list *list, int prec_len);
int				ft_type(const char *str, int i, t_list *stru);
int				ft_count_convers(const char *str);
void			ft_print_nb(int nb, t_list *list, int prec_len);
void			ft_print_p(void	*addr, t_list *list, int prec_len);
char			*ft_itoa_base(long nb, char *base);
void			ft_print_x(unsigned int n, t_list *list, int prec_len, char type);
void			ft_putunsign(unsigned int nb);
void			ft_print_u(unsigned int nb, t_list *list, int prec_len);

#endif
