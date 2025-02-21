/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mle-brie <mle-brie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/03 13:52:38 by mle-brie          #+#    #+#             */
/*   Updated: 2024/12/06 13:14:12 by mle-brie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_and_store(int fd, char *stock, char *buffer)
{
	ssize_t		bytes_read;
	char		*tmp;

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
			break ;
		buffer[bytes_read] = '\0';
		tmp = ft_strjoin(stock, buffer);
		if (!tmp)
			return (free(stock), NULL);
		free(stock);
		stock = tmp;
		if (ft_strchr(stock, '\n'))
			break ;
	}
	if (bytes_read < 0)
	{
		free (stock);
		stock = NULL;
	}
	return (stock);
}

char	*extract_line(char **stock)
{
	char	*newline_pos;
	size_t	line_size;
	char	*line;

	newline_pos = ft_strchr(*stock, '\n');
	if (newline_pos)
	{
		line_size = newline_pos - *stock + 1;
		line = (char *)malloc(sizeof(char) * line_size + 1);
		if (!line)
			return (NULL);
		ft_strlcpy(line, *stock, line_size + 1);
		ft_strlcpy(*stock, newline_pos + 1, ft_strlen(newline_pos + 1) + 1);
	}
	else
	{
		line = ft_strdup(*stock);
		if (!line)
			return (free(*stock), NULL);
		free(*stock);
		*stock = NULL;
	}
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*stock = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	if (!stock)
	{
		stock = ft_strdup("");
		if (!stock)
			return (free(stock), NULL);
	}
	stock = read_and_store(fd, stock, buffer);
	free(buffer);
	if (!stock)
		return (NULL);
	if (*stock == '\0')
		return (free(stock), stock = NULL, NULL);
	line = extract_line(&stock);
	return (line);
}

// int main(int argc, char *argv[])
// {
//     int fd;
//     char *line;

//     if (argc != 2)
//     {
//         printf("Usage: %s <1 filename>\n", argv[0]);
//         return (1);
//     }

//     fd = open(argv[1], O_RDONLY);
//     if (fd == -1)
//     {
//         printf("Error opening file\n");
//         return (1);
//     }
// 	int i = 0;
//     while (i < 9)
//     {
// 		line = get_next_line(fd);
//         printf("%s", line);
// 		i++;
//     }
//     close(fd);
//     return (0);
// }
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 
// 

/*
first call, return the first line
every new call is the next line
	-> so, static variable to stock things

read(fd, buffer[buffer], n-bytes[buffer in .h])
	always read = bytes_read, because read is an int

Create a function to read the file and stock everything after the first \n
	bytes_read = read fd into buffer for BUFFER_SIZE bytes
		break if not working
	buffer[bytes_read] = '\0' --> last character is null, always
	temp is strjoin of what's in stock with the new buffer read
		check it did work : return(free(stock), NULL)
	free stock to give it the new value of temp
	if strchr of \n inside stock, return stock
	last security check : if bytes_read < 0, free stock = NULL
	return stock
	=> stock = read_and_stock(fd, stock, buffer);

Function to extract what is a line from the stock of the previous function
/!\ use **stock, because you want the static stock, not a simple stock /!\
	newline_pos = strchr(stock, '\n')
	if (newline_pos) // ie. if there is a \n
		line_size = newline_pos - stock + 1 // coz strchr is evrthg after it
		line = malloc(...line_size + 1);
			check if it worked
		strlcpy(line, stock, line_size) // line = stock for the size of the line
		& strlcpy(*stock, newline_pos + 1, strlen(newline_pos + 1) + 1)
	else //ie. if there is no \n
		line = strdup(*stock);
		free(*stock);
		*stock = NULL; // don't forget the *, okay?
	return (line);
	=> line = extract_line(&stock)

you can return multiple steps, like 
	return (free(), NULL);

if empty or end, line = (null);

*/