/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minilib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqiyu <iqiyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:23:29 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/11 16:31:16 by iqiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINILIB_H
# define MINILIB_H

# include <stdlib.h>
# include <unistd.h>

enum e_errors	{SUCCESS, 	//0
	ARG_NUMBER, 			//1
	END, 					//2
	MALLOC_ERROR,			//3
	EXEC_FILE,				//4
	DIR_NOT_FOUND,			//5
	INPUT_ERROR,			//6
	QUOTE_ERROR,			//7
	UNKNOW_COMMAND,			//8
	UNKNOW_ERROR,			//9
	FILE_NOT_FOUND,			//10
	OPEN_ERROR,				//11
	FORK_ERROR};			//12
typedef struct s_token {
	char			*content;
	struct s_token *next;
	struct s_token *prev;
} t_token;

t_token	*mini_split(char *str, char **charset, int *error);
char	**mini_ft_split(char *str, char c);
int		mini_tablen(char **tab);
int		mini_strlen(char *str);
char	*mini_strjoin(char *s1, char *s2);
char	*mini_strdup(char *s1);
int		mini_strcmp(char *s1, char *s2, int ended);
int		mini_lrstrcmp(char *s1, char *s2);
int		mini_is_intab(char **tab, char *str);
char	*mini_cut_to(char *str, char c);
int		mini_charfind(char *str, char c);
void	mini_freetab(char **tab);
int		mini_strcpy(char *src, char *dst);
void    mini_putstr_fd(int fd, char *str);
char    *mini_append_path(char *s1, char *s2);
int 	mini_is_valid_func(char *path, char *str);
int		is_mini_func(char *str);
char    *mini_itoa(int n);
void	*mini_calloc(size_t count, size_t size);
void	mini_bzero(void *s, size_t n);
char    *mini_tolower(char *str);

/* tokens */
void    mini_tokenclear(t_token *lst); // clear la liste
t_token *mini_tokenlast(t_token *lst); // donne le dernier element
int    mini_tokenadd_back(t_token **lst, t_token *token); // ajoute a la fin de la liste
t_token *mini_tokennew(char *str); // creer un nouvel element avec comme contenu str
void    mini_tokenwrite(t_token *lst); // ecrit toute la liste
t_token *mini_tokenfirst(t_token *lst); // retourne le premier element

#endif