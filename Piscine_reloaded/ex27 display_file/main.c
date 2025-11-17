#include <fcntl.h> // For O_RDONLY
#include <unistd.h>

int	ft_display_file(char *filename)
{
    int		fd;
    char	buffer[4096];
    ssize_t	bytes_read;

    fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        write(2, "Cannot read file.\n", 18);
        return (1);
    }
    bytes_read = read(fd, buffer, sizeof buffer);
    while (bytes_read > 0)
    {
        write(1, buffer, bytes_read);
        bytes_read = read(fd, buffer, sizeof buffer);
    }
    close(fd);
    return (0);
}

int	main(int argc, char **argv)
{
    if (argc == 1)
    {
        write(2, "File name missing.\n", 19);
        return (1);
    }
    else if (argc > 2)
    {
        write(2, "Too many arguments.\n", 20);
        return (1);
    }
    return (ft_display_file(argv[1]));
}