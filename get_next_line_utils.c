#include "get_next_line.h"

char *ft_join(char *s1, char *s2)
{
	if (!s1 && !s2)
		return (NULL);
	else if(!s1 && s2)
		return (strdup(s2));
	else if(!s2 && s1)
		return (s1);
	else
	{
		int len = ft_strlen(s1) + ft_strlen(s2);
		char *ret = malloc(len + 1);

		int i = 0;
		while(s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
		int j = 0;
		while(s2[j])
		{
			ret[i] = s2[j];
			j++;
			i++;
		}
		free(s1);
		ret[i] = '\0';
		return (ret);
	}
}

int ft_strlen(char *s)
{
	int i;

	i = 0;
	while(s[i])
		i++;
	return (i);
}

char *ft_sub(char *s)
{
    int i;
	char *ret;
	int	new_line;
	int j;

    if (!s)
        return NULL;
	i = 0;
	j = 1;
	new_line = 0;
    while (s[i] && s[i] != '\n')
        i++;
	if (s[i] == '\n')
	{
		new_line = 1;
		j = 2;
	}
    ret = malloc(i + j);
    if (!ret)
        return NULL;
	j = 0;
    while (j < i)
	{
        ret[j] = s[j];
		j++;
	}
	if(new_line)
	{
		ret[i] = '\n';
		i++;
	}
    ret[i] = '\0';
    return ret;
}
