#include "libft.h"

int	main(int argc, char **argv)
{
	int		fd;
    char **argv2 = argv;

	while (argc-- - 1)
	{
		if ((fd = open(*(++argv), O_RDONLY)) == -1)
			return (printf("Fucked up\n"), 1);
		printf("\n\nBegoth, the file number %i:\n\n", (int)(argv - argv2));
        for (char * line = get_next_line(fd); line != NULL; line = get_next_line(fd))
            printf("%s", line);
	}
	return (close (fd), 0);
}
