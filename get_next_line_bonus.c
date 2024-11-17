/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yaajagro <yaajagro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/13 14:27:52 by yaajagro          #+#    #+#             */
/*   Updated: 2024/11/17 16:56:17 by yaajagro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*ft_nextline(char *s)
{
	int		i;
	char	*ret;
	int		len;
	int		j;

	if (!s)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\0')
		return (free(s), NULL);
	len = ft_strlen(s) - i;
	ret = malloc(len + 1);
	if (!ret)
		return (free(s), NULL);
	i++;
	j = 0;
	while (s[i])
		ret[j++] = s[i++];
	ret[j] = '\0';
	return (free(s), ret);
}

static int	check(char *s)
{
	int	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_read(char *s, char *buffer, int fd)
{
	int	readed;

	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed <= 0)
			break ;
		buffer[readed] = '\0';
		s = ft_join(s, buffer);
		if (!s)
			return (free(buffer), NULL);
		if (check(s))
			break ;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s[10240];
	char		*buffer;

	if (fd >= 10240)
		return (NULL);
	if (BUFFER_SIZE <= 0 || read(fd, NULL, 0) < 0)
		return (free(s[fd]), s[fd] = NULL);
	buffer = malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!buffer)
		return (free(s[fd]), NULL);
	s[fd] = ft_read(s[fd], buffer, fd);
	free(buffer);
	buffer = s[fd];
	buffer = ft_sub(buffer);
	s[fd] = ft_nextline(s[fd]);
	return (buffer);
}
