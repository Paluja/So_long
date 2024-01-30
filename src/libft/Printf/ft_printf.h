/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pjimenez <pjimenez@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/01 19:24:43 by pjimenez          #+#    #+#             */
/*   Updated: 2024/01/30 11:15:27 by pjimenez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef  FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
//este tipo de de dato puede almacenar un ptr con datos (type = void*)
//por lo que se podria decir que que tanto el void * y uintptr_t tendrian 
//la misma longitud
typedef unsigned long int	uintptr_t;
int		ft_printchar(char c);
int		ft_printstr(char *s);
int 	ft_printnbr(int n);
int		ft_printPtr(uintptr_t n);
int 	ft_printUnbr(unsigned int n);
int		ft_printxX(unsigned int n, char const str);
int	    ft_strlen(const char *str);
char	*ft_itoa(int n);
int		ft_printf(char const *str, ...);
void	ft_putchar_fd(char c, int fd);

#endif