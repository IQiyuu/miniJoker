/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:34:13 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 11:45:36 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* FONCTION QUI PARSE LES INPUT DE L'UTILISATEUR EN TOKENS */
/* */
/* prend en argument t_miniJoker pour les tokens */
/* prend en argument une chaine de caractere qui est les input de l'utilisateur */
/* renvoie 1 si le programme doit se fermer 0 sinon */
int    parser(t_miniJoker *mini, char *input)
{
  if (!input)
  {
    mini->tokens = NULL;
    return (1);
  }
  mini->tokens = mini_split(input, mini->sep);
  if (remove_encapsuled(mini))
  {
    printf("error unclosed quote\n");
    return (2);
  }
  if (mini_strcmp(mini->tokens[0], "exit", 0) == 0)
    return (1);
  return (0);
}