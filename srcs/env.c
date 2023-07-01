/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: romartin <romartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 20:21:06 by iqiyu             #+#    #+#             */
/*   Updated: 2023/06/30 14:11:28 by romartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniJoker.h"

char    *getEnv(t_miniJoker *mini, char *str)
{
    int i;

    i = 0;
    while (mini->env_copy[i])
    {
        if (ft_lrstrcmp(mini->env_copy[i++], str) == 0)
            return (&mini->env_copy[i - 1][ft_charfind(mini->env_copy[i - 1], '=') + 1]);
    }
    return (NULL);
}
