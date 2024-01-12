/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:24:43 by pjimenez          #+#    #+#             */
/*   Updated: 2023/09/23 20:56:30 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef unsigned long int	t_uintptr;
int							ft_printchar(char c);
int							ft_printstr(char *s);
int							ft_printnbr(int n);
int							ft_printptr(uintptr_t n);
int							ft_printunbr(unsigned int n);
int							ft_printx(unsigned int n, char const str);
size_t						ft_strlen(const char *str);
char						*ft_itoa(int n);
int							ft_printf(char const *str, ...);
void						ft_putchar_fd(char c, int fd);

#endif