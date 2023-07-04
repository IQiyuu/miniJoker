/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniJoker.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 12:22:54 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 12:43:54 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIJOKER_H
# define MINIJOKER_H

# include <stdio.h>
# include <signal.h>
# include <unistd.h>
# include <readline/readline.h>
# include <readline/history.h>
# include <sys/time.h>
# include <dirent.h>
# include <sys/types.h>
# include "minilib.h"

# ifndef EXIT_SUCESS
#  define EXIT_SUCCESS 0
# endif
# ifndef EXIT_FAILLURE
#  define EXIT_FAILLURE 1
# endif
# ifndef PROMPT
#  define PROMPT "\x1b[30mmini\x1b[31mJoker\x1b[0m> "
# endif

typedef struct s_minijoker {
	char	**env_copy;
	char	*sep[7];
	char	**tokens;
	int		index;
}	t_minijoker;

/* BUILTIN */
int		mini_env(t_minijoker *mini);
int		mini_echo(t_minijoker *mini);
int		mini_pwd(void);
int		mini_cd(t_minijoker *mini);
int		mini_export(t_minijoker *mini);
int		mini_unset(t_minijoker *mini);

void	listen(t_minijoker *mini);
int		parser(t_minijoker *mini, char *input);
void	sigint(int code);
void	exit_minijoker(t_minijoker *mini, char *str);
char	*get_env(t_minijoker *mini, char *str);
int		true_exec(t_minijoker *mini, int i);
int		mini_exec(t_minijoker *mini);
void	freetab(char **tab);
void	exec_loop(char *str, t_minijoker *mini);
int		is_mini_func(t_minijoker *mini, int i);
int		remove_encapsuled(t_minijoker *mini);

#endif