/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:22:14 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/27 11:08:53 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <limits.h>
# include <stdarg.h>
# include <stdint.h>

int		ft_printf(const char *input, ...);
int		print_char(va_list args);
int		print_string(va_list args);
int		print_num(va_list args);
int		print_unsigned(va_list args);
int		print_lowhex(va_list args);
int		print_uphex(va_list args);
int		print_pointer(va_list args);

char	*utoa(unsigned int nUm);
char	*hexformula(unsigned long n);

char	*ft_itoa(int n);
void	ft_putstr_fd(char *s, int fd);
int		ft_toupper(int c);
size_t	ft_strlen(char *str);

#endif