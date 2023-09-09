/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/09/06 19:59:26 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

void	listen(t_minijoker *mini)
{
	char	*str;

	while (1)
	{
		mini->lerror = mini->error;
		mini->error = SUCCESS;
		mini->redir_fd = -1;
		printf("\x1b[2K\x1b[0G");
		str = readline(PROMPT);
		if (!str)
		{
			exit_minijoker(mini, NULL);
		}
		parser(mini, str);
		mini->first = mini->tokens;
		if (mini->tokens)
		{
			if (mini->end == 1)
				exit_minijoker(mini, str);
			if (mini->error != QUOTE_ERROR)
				redirection(mini);
			add_history(str);
			mini_tokenclear(mini->first);
			mini->tokens = NULL;
		}
		free(str);
	}
}
