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
	int len = strlen(s1) + strlen(s2);
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

char *ft_nextline(char *s)
{
	int i = 0;
	if (!s)
		return NULL;
	int len = strlen(s);
	while(s[i] && s[i] != '\n')
		i++;
	int j = 0;
	char *ret = malloc(len - i + 1);
	while(s[i])
	{
		ret[j++] = s[i++];
	}
	free(s);
	ret[j] = '\0';
	return (ret);
}
int check(char *s)
{
	int i = 0;
	while(s[i])
	{
		if(s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}
char *ft_sub(char *s)
{
	int i = 0;
	while(s[i] && s[i] != '\n')
		i++;
	char *ret = malloc(i + 1);
	if (!ret)
		return (NULL);
	i = 0;
	while(s[i] && s[i] != '\n')
	{
		ret[i] = s[i];
		i++;
	}
	ret[i] = '\0';
	return (ret);
}