#include "get_next_line.h"

char *ft_nextline(char *s)
{
    int i;
    char *ret;
	int len;
	int j;

    if (!s)
        return NULL;
	i = 0;
    while (s[i] && s[i] != '\n')
        i++;
    if (s[i] == '\0')
	{
        free(s);
        return (NULL);
    }
    len = ft_strlen(s) - i;
    ret = malloc(len + 1);
    if (!ret)
        return NULL;
    i++;
    j = 0;
    while (s[i])
        ret[j++] = s[i++];
    ret[j] = '\0';
    free(s);
    return ret;
}

int check(char *s)
{
    int i = 0;
    while (s[i])
    {
        if (s[i] == '\n')
            return 1;
        i++;
    }
    return 0;
}

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
	tmp = s;
	tmp = ft_sub(tmp);
	s = ft_nextline(s);
	return (tmp);
}
