#include "get_next_line.h"


char *get_next_line(int fd)
{
	char *buffer = NULL;
	static char *s = NULL;
	char *tmp = NULL;
	int readed = 1;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(BUFFER_SIZE + 1);
	if(!buffer)
		return (NULL);
	while(readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if(readed <= 0)
			break;
		buffer[readed] = '\0';
		s = ft_join(s, buffer);
		if(check(s))
			break;
	}
	free(buffer);
	if (s)
	{
		tmp = s;
		tmp = ft_sub(tmp);
		s = ft_nextline(s);
	}
	return (tmp);
}