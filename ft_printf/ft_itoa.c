/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 11:41:51 by mle-brie          #+#    #+#             */
/*   Updated: 2024/11/25 15:26:40 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	num_length(int n)
{
	int	len;

	len = 0;
	if (n == 0)
		len = 1;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*result;
	int		len;
	long	num;

	len = num_length(n);
	num = n;
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (NULL);
	result[len--] = '\0';
	if (n == 0)
		return (result[0] = '0', result);
	if (num < 0)
	{
		result[0] = '-';
		num = -num;
	}
	while (num > 0)
	{
		result[len--] = (num % 10) + '0';
		num /= 10;
	}
	return (result);
}

// int	num_size(int n)
// {
// 	int	len;

// 	len = 0;
// 	if (n < 0)
// 		n = -n;
// 	while (n != 0)
// 	{
// 		n /= 10;
// 		len++;
// 	}
// 	return (len);
// }

// int	main(void)
// {
// 	int	test = 2147483647;
// 	int	fd;
// 	size_t	len;

// 	len = num_size(test);
// 	fd = open("test.txt", O_WRONLY);
// 	if (fd == -1)
// 		return (1);
// 	ft_putnbr_fd(test, fd);
// 	if (close(fd) == -1)
// 		return (1);
// 	fd = open("test.txt", O_RDONLY);
// 	if (fd == -1)
// 		return (1);
// 	char	buffer[len + 1];
// 	ssize_t	bytes_read = read(fd, buffer, len + 1);
// 	if (bytes_read == -1)
// 	{
// 		close(fd);
// 		return (1);
// 	}
// 	buffer[bytes_read] = '\0';
// 	printf("The file shall transform: %s\n", buffer);
// 	close(fd);
// 	return (0);
// }