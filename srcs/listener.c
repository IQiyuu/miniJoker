/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqiyu <iqiyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/11 17:05:09 by iqiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* FONCTION BOUCLE INFINI QUI LIT LES INPUT DE L'UTILISATEUR */
/* */
/* prend en argument t_minijoker */
/* */
/* renvoie rien */
void	listen(t_minijoker *mini)
{
	char	*str;

	while (1)
	{
		mini->lerror = mini->error;
		mini->error = SUCCESS;
		mini->redir_fd = -1;
		str = readline(PROMPT);
		parser(mini, str);
		if (mini->tokens)
		{
			if (mini->error == END)
				exit_minijoker(mini, str);
			if (mini->error != QUOTE_ERROR)
				redirection(mini);
			add_history(str);
			mini_tokenclear(mini->tokens);
		}
		free(str);
	}
}
