#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*bytesr;
	char		*line;
	char		*buffer;

	line = NULL;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(bytesr);
		free(buffer);
		bytesr = NULL;
		buffer = NULL;
		return (NULL);
	}
	if (!buffer)
		return (NULL);
	bytesr = bytesr_filling(fd, bytesr, buffer);
	if (*bytesr == 0)
	{
		free (bytesr);
		return (bytesr = 0);
	}
	line = extract_line(bytesr, line);
	bytesr = extract_new_bytesr(bytesr);
	return (line);
}

char	*bytesr_filling(int fd, char *bytesr, char *buffer)
{
	ssize_t	nbytes;

	nbytes = 1;
	if (!bytesr)
		bytesr = ft_strdup("");
	while (nbytes > 0)
	{
		nbytes = read(fd, buffer, BUFFER_SIZE);
		if (nbytes == -1)
		{
			free (buffer);
			return (NULL);
		}
		buffer[nbytes] = 0;
		bytesr = ft_strjoin (bytesr, buffer);
		if ((ft_strchr(buffer, '\n')))
			break ;
	}
	free (buffer);
	return (bytesr);
}

char	*extract_new_bytesr(char	*bytesr)
{
	int		len;
	int		i;
	char	*new_bytesr;

	len = 0;
	i = 0;
	if (bytesr == NULL)
		return (NULL);
	while (bytesr[len] != '\n' && bytesr[len])
		len++;
	if (bytesr[len] == '\n')
		len++;
	new_bytesr = malloc((ft_strlen(bytesr) - len + 1) * sizeof(char));
	if (!new_bytesr)
		return (NULL);
	while (bytesr[len + i])
	{
		new_bytesr[i] = bytesr[len + i];
		i++;
	}
	free (bytesr);
	new_bytesr[i] = 0;
	return (new_bytesr);
}

char	*extract_line(char *bytesr, char *line)
{
	int	len;
	int	i;

	len = 0;
	i = 0;
	if (bytesr == NULL)
		return (NULL);
	while (bytesr[len] != '\n' && bytesr[len])
		len++;
	if (bytesr[len] == '\n')
		len++;
	line = malloc((len + 1) * sizeof(char));
	if (!line)
		return (NULL);
	while (i < len)
	{
		line[i] = bytesr[i];
		i++;
	}
	line[i] = 0;
	return (line);
}