/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_pipe.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/15 14:29:23 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/10 15:17:11 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

static void	exec_pipe(t_minijoker *mini, int pipefd[2])
{
	close(pipefd[1]);
	dup2(pipefd[0], STDIN_FILENO);
	while (mini->tokens)
	{
		if (mini_strcmp(mini->tokens->content, "|", 0) == 0)
		{
			mini->tokens = mini->tokens->next;
			break ;
		}
		if (mini->tokens)
			mini->tokens = mini->tokens->next;
	}
	if (mini_tokenfindchar(mini->tokens, '|', 1))
		mini_pipe(mini);
	else if (mini->tokens)
		exec_loop(mini);
}

int	mini_pipe(t_minijoker *mini)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	if (pipe(pipefd) == -1)
		return (0);
	pid = fork();
	if (pid < 0)
		return (0);
	if (pid == 0)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT_FILENO);
		exec_loop(mini);
		exit(0);
	}
	else
		exec_pipe(mini, pipefd);
	wait(&status);
	return (0);
}
