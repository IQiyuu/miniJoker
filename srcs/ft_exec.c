/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqiyu <iqiyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 17:23:12 by iqiyu             #+#    #+#             */
/*   Updated: 2023/07/04 01:56:01 by iqiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* (WIP) FONCTION QUI VERIFIE SI LA CHAINE DEMANDE EST UN BUILTIN */
/* */
/* prend en argument t_miniJoker qui a le tableau des tokens */
/* prend en argument un int qui correspond a l index de la chaine cherche */
/* */
/* renvoie 1 si la fonction est un builtin 0 sinon */
int is_ft_func(t_miniJoker *mini, int i)
{
	if (ft_strcmp(mini->tokens[i], "echo", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "cd", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "pwd", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "env", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "export", 0) == 0)
		return (1);
	if (ft_strcmp(mini->tokens[i], "unset", 0) == 0)
		return (1);
	return (0);
}

/* (WIP) FONCTION QUI EXECUTE LES FONCTIONS BUILTIN */
/* */
/* prend en arguments les tokens /!\ CA NE GERE QUE LA PREMIERE COMMANDE /!\ */
/* */
/* renvoie -1 si aucune commande n'est execute */
int	exec_ft(t_miniJoker *mini)
{
	int	error;

	error = 1;
	if (ft_strcmp(mini->tokens[0], "echo", 0) == 0)
		error = ft_echo(mini);
	if (ft_strcmp(mini->tokens[0], "cd", 0) == 0)
		error = mini_cd(mini);
	if (ft_strcmp(mini->tokens[0], "env", 0) == 0)
		error = ft_env(mini);
	return (error);
}
