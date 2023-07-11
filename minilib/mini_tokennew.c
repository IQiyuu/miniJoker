/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokennew.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqiyu <iqiyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 09:41:11 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/11 13:34:22 by iqiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

t_token *mini_tokennew(char *str)
{
    t_token *token;

    token = NULL;
    if (str)
    {
        token = (t_token *)malloc(sizeof(t_token));
        if (!token)
            return NULL;
        token->content = str;
        token->prev = NULL;
        token->next = NULL;
    }
    return (token);
}
