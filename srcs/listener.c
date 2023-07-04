/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listener.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqiyu <iqiyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/19 14:23:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 01:55:35 by iqiyu            ###   ########.fr       */
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
    char    buff[BUFFER_SIZE];

    while (1)
    {
        str = readline(PROMPT);
        mini->index = 0;
        error = parser(mini, str);
        if (error == 1)
            exit_miniJoker(mini, str);
        if (!error)
            exec_loop(str, mini);
        add_history(str);
        //apply_redirection(mini);
        free(str);
        freetab(mini->tokens);
    }
}
