/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/07 14:17:41 by dgoubin          ###   ########.fr       */
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
		error = parser(mini, str);
		if (error == END)
			exit_minijoker(mini, str);
		if (error != QUOTE_ERROR)
			redirection(mini);
		add_history(str);
		free(str);
		mini_tokenclear(mini->tokens);
	}
}
