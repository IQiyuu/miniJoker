/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 16:38:55 by dgoubin          ###   ########.fr       */
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
	int		error;

	while (1)
	{
		str = readline(PROMPT);
		mini->index = 0;
		error = parser(mini, str);
		if (error == END)
			exit_minijoker(mini, str);
		if (error != QUOTE_ERROR)
			exec_loop(str, mini);
		add_history(str);
		//apply_redirection(mini);
		free(str);
		mini_freetab(mini->tokens);
	}
}
