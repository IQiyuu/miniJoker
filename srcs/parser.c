/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/08 16:52:36 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* FONCTION QUI PARSE LES INPUT DE L'UTILISATEUR EN TOKENS */
/* */
/* prend en argument t_minijoker pour les tokens */
/* prend en argument une chaine de caractere qui est les input */
/*		de l'utilisateur */
/* renvoie 1 si le programme doit se fermer 0 sinon */
void	parser(t_minijoker *mini, char *input)
{
	if (!input)
	{
		mini->tokens = NULL;
		mini->error = END;
		return ;
	}
	mini->tokens = mini_split(input, mini->sep, &mini->error);
	if (mini->error == QUOTE_ERROR)
	{
		mini_putstr_fd(2, "parsing error: quote unclosed\n");
		return ;
	}
	if (mini_strcmp(mini->tokens->content, "exit", 0) == 0)
	{
		mini->error = END;
		return ;
	}
}
