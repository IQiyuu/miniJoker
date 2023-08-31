/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:53:42 by iqiyu             #+#    #+#             */
/*   Updated: 2023/08/31 13:59:05 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

char	*freetab(char **tab)
{
	int	i;

	if (!tab)
		return (NULL);
	i = 0;
	while (tab[i])
		free(tab[i++]);
	return (NULL);
}

static int	error_test(t_minijoker *mini, int error)
{
	if (mini->tokens && mini->tokens->next)
	{
		if (mini->tokens->next->content
			&& mini_has_alpha(mini->tokens->next->content))
		{
			mini_putstr_fd(2, "miniJoker: exit: ");
			mini_putstr_fd(2, mini->tokens->next->content);
			mini_putstr_fd(2, ": numeric argument required\n");
			error = NUM_ARG;
		}
		else
			error = mini_atoi(mini->tokens->next->content);
	}
	return (error);
}

void	exit_minijoker(t_minijoker *mini, char *str)
{
	int	error;
	int	i;

	write(1, "exit\n", 5);
	i = 0;
	error = mini->error;
	if (error == END)
		error = SUCCESS;
	error = error_test(mini, error);
	freetab(mini->env_copy);
	free(mini->env_copy);
	if (mini->tokens)
		mini_tokenclear(mini->tokens);
	free(str);
	rl_clear_history();
	system("leaks minijoker");
	exit(error);
}
