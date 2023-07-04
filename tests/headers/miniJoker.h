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
#ifndef PROMPT
# define PROMPT "\x1b[30mmini\x1b[31mJoker\x1b[0m> "
#endif

typedef struct  s_miniJoker {
	char	**env_copy;
	char	*sep[7];
	char	**tokens;
	int		index;
} t_miniJoker;

/* BUILTIN */
int		mini_env(t_miniJoker *mini);
int		mini_echo(t_miniJoker *mini);
int		mini_pwd(void);
int		mini_cd(t_miniJoker *mini);
int		mini_export(t_miniJoker *mini);
int		mini_unset(t_miniJoker *mini);

void	listen(t_miniJoker *mini);
int		parser(t_miniJoker *mini, char *input);
void	sigint(int code);
void	exit_miniJoker(t_miniJoker *mini, char *str);
char	*getEnv(t_miniJoker *mini, char *str);
int		true_exec(t_miniJoker *mini, int i);
int		mini_exec(t_miniJoker *mini);
void	freetab(char **tab);
void	exec_loop(char *str, t_miniJoker *mini);
int		is_mini_func(t_miniJoker *mini, int i);
int		remove_encapsuled(t_miniJoker *mini);

#endif