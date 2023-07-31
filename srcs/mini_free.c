/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_free.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 18:53:42 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/31 17:13:18 by dgoubin          ###   ########.fr       */
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

void	exit_minijoker(t_minijoker *mini, char *str)
{
	int	error;
	int	i;

	i = 0;
	error = mini->error;
	if (mini->tokens && mini->tokens->next)
	{
		while (mini->tokens->next->content[i])
		error = mini_atoi(mini->tokens->next->content);
	}
	freetab(mini->env_copy);
	free(mini->env_copy);
	if (mini->tokens)
		mini_tokenclear(mini->tokens);
	free(str);
	rl_clear_history();
	//system("leaks minijoker");
	write(1, "exit\n", 5);
	exit(error);
}
