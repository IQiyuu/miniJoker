/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_is_intab.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:04:17 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 11:05:18 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

int mini_is_intab(char **tab, char *str)
{
    int i;

    i = 0;
    while (tab[i])
    {
        if (mini_strcmp(tab[i], str, 1) == 0)
            return (1);
        i++;
    }
    return (0);
}