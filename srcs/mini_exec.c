/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:23:12 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/04 12:46:06 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* (WIP) FONCTION QUI VERIFIE SI LA CHAINE DEMANDE EST UN BUILTIN */
/* */
/* prend en argument t_minijoker qui a le tableau des tokens */
/* prend en argument un int qui correspond a l index de la chaine cherche */
/* */
/* renvoie 1 si la fonction est un builtin 0 sinon */
int	is_mini_func(t_minijoker *mini, int i)
{
	if (mini_strcmp(mini->tokens[i], "echo", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens[i], "cd", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens[i], "pwd", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens[i], "env", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens[i], "export", 0) == 0)
		return (1);
	if (mini_strcmp(mini->tokens[i], "unset", 0) == 0)
		return (1);
	return (0);
}

/* (WIP) FONCTION QUI EXECUTE LES FONCTIONS BUILTIN */
/* */
/* prend en arguments les tokens /!\ CA NE GERE QUE LA PREMIERE COMMANDE /!\ */
/* */
/* renvoie -1 si aucune commande n'est execute */
int	mini_exec(t_minijoker *mini)
{
	int	error;

	error = 1;
	if (mini_strcmp(mini->tokens[0], "echo", 0) == 0)
		error = mini_echo(mini);
	if (mini_strcmp(mini->tokens[0], "cd", 0) == 0)
		error = mini_cd(mini);
	if (mini_strcmp(mini->tokens[0], "unset", 0) == 0)
		error = mini_unset(mini);
	if (mini_strcmp(mini->tokens[0], "export", 0) == 0)
		error = mini_export(mini);
	if (mini_strcmp(mini->tokens[0], "env", 0) == 0)
		error = mini_env(mini);
	return (error);
}