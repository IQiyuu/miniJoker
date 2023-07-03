/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/03 17:48:24 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

/* FONCTION BOUCLE INFINI QUI LIT LES INPUT DE L'UTILISATEUR */
/* */
/* prend en argument t_miniJoker */
/* */
/* renvoie rien */
void    listen(t_miniJoker *mini)
{
    char    *str;
    int     error;

    while (1)
    {
        str = readline(PROMPT);
        mini->index = 0;
        error = parser(mini, str);
        if (error)
            exit_miniJoker(mini, str);
        exec_loop(str, mini);
        add_history(str);
        //apply_redirection(mini);
        free(str);
        freetab(mini->tokens);
    }
}
