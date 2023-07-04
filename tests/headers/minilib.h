#ifndef MINILIB_H
# define MINILIB_H

# include <stdlib.h>

char	**mini_split(char *str, char **charset);
char	**mini_ft_split(char *str, char c);
int     mini_tablen(char **tab);
int 	mini_strlen(char *str);
char	*mini_strjoin(char *s1, char *s2);
char	*mini_strdup(char *s1);
int     mini_strcmp(char *s1, char *s2, int ended);
int     mini_lrstrcmp(char *s1, char *s2);
int     mini_is_intab(char **tab, char *str);
char	*mini_cut_to(char *str, char c);
int	    mini_charfind(char *str, char c);
void    mini_freetab(char **tab);

#endif