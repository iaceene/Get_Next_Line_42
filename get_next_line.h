#ifndef GET_NEXT_LINE_H
#define GET_NEXT_LINE_H
#include "libc.h"
#ifndef BUFFER_SIZE
#define BUFFER_SIZE 12
#endif

char *get_next_line(int fd);
char *ft_join(char *s1, char *s2);
char *ft_nextline(char *s);
int check(char *s);
char *ft_sub(char *s);

#endif