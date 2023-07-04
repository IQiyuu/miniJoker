/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 11:05:53 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/04 11:42:26 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minilib.h"

static char	**quit(char **res)
{
	mini_freetab(res);
	return (NULL);
}

static int	nb_of_words(char *str, char **charset, int i)
{
	int	size;
	int	n;

	size = 0;
	while (str[i] == ' ')
		i++;
	while (str[i])
	{
		n = -1;
		while (charset[++n])
		{
			if (mini_strcmp(charset[n], &str[i], 1) == 0)
			{
				if (str[i + mini_strlen(charset[n])] != '\0')
					size++;
				while (str[i] && !mini_strcmp(charset[n], &str[i], 1))
					i += mini_strlen(charset[n]);
				break ;
			}
		}
		if (!charset[n])
			i++;
	}
	if (size != 0 || (size == 0 && str[0] != '\0'))
		size++;
	return (size);
}

static int	count_words(char *str, char **charset, int *i)
{
	int cpt;
	int	n;

	cpt = *i;
    while (str[cpt])
    {
        n = 0;
        while (charset[n])
        {
            if (mini_strcmp(charset[n], &str[cpt], 1) == 0)
                break ;
            n++;
        }
        if (charset[n])
            break;
        cpt++;
    }
    if (cpt - (*i) == 0 && charset[n])
        cpt = mini_strlen(charset[n]);
	return (cpt);
}

static char    *ministrdup(char *str, char **charset, int *i)
{
    int cpt;
    char    *res;
    int j;

    if (!str || !str[*i])
        return (NULL);
    cpt = count_words(str, charset, i);
    res = (char *)malloc(sizeof(char) * (cpt - *i + 1));
    if (!res)
        return (NULL);
    j = 0;
    while (cpt - *i > 0)
    {
        res[j] = str[*i];
        j++;
        (*i)++;
    }
    res[j] = '\0';
    if (str[*i] == ' ')
        (*i)++;
    return (res);
}

char	**mini_split(char *str, char **charset)
{
	int		size;
	int		i;
	int		j;
	char	**res;

	size = nb_of_words(str, charset, 0);
	res = (char **)malloc(sizeof(char *) * (size + 1));
	if (!res)
		return (NULL);
	j = 0;
	i = 0;
	while (j < size)
	{
		while (str[i] == ' ')
			i++;
		if (!str[i])
			break ;
		res[j++] = ministrdup(str, charset, &i);
		if (!res)
			return (quit(res));
	}
	res[j] = NULL;
	return (res);
}
