/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_tokenwrite.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqiyu <iqiyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 10:11:45 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/11 12:16:05 by iqiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"
#include <stdio.h>

void    mini_tokenwrite(t_token *lst)
{
    while (lst)
    {
        if (lst->content)
            printf("-%s-\n", lst->content);
        lst = lst->next;
    }
}
