#include "get_next_line_bonus.h"

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
	static char *s[10240];
	char *tmp = NULL;
	int readed = 1;

    if (fd > 10240)
        return (NULL);
    if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
        return (free(s[fd]), s[fd] = NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if(!buffer)
		return (NULL);
	while(readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if(readed <= 0)
			break;
		buffer[readed] = '\0';
		s[fd] = ft_join(s[fd], buffer);
        if (!s[fd])
            return (free(buffer), NULL);
		if(check(s[fd]))
			break;
	}
	free(buffer);
	tmp = s[fd];
	tmp = ft_sub(tmp);
	s[fd] = ft_nextline(s[fd]);
	return (tmp);
}
