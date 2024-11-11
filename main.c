#include "get_next_line.h"

void ft(void)
{
	system("leaks a.out");
}

int main(int c, char **v)
{
	// atexit(ft);
	if (c != 2)
		return (0);
	int fd = open(v[1], O_RDONLY);
	if(fd == - 1)
		return (0);
	char *tmp = get_next_line(fd);
	// while (tmp)
	// {
		printf("[--> %s <--]", tmp);
		free(tmp);
		tmp = get_next_line(fd);
		printf("[--> %s <--]", tmp);
		free(tmp);
		tmp = get_next_line(fd);
		printf("[--> %s <--]", tmp);
		free(tmp);
	// }
	return (0);
}