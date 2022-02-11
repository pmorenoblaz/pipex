#include "pipex.h"

void	ft_open_infile(char *str)
{
	int	fd;
	size_t	len;

	fd = open(str, O_RDONLY);
	if (fd < 0)
	{
		write(1, "zsh: no such file or directory: ", 32);
		len = ft_strlen(str);
		write(1, str, len);
		exit(0);
	}
	// dup2(fd, nuevofd); 
	//Pasar del archivo de lectura al de escritura
}
