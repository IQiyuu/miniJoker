/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqiyu <iqiyu@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:11:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/11 13:25:19 by iqiyu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>
/*
int main()
{
    int fd1 = open("CouCou", O_RDWR | O_CREAT | O_TRUNC);
    int fd = 1;
    pid_t pid = fork();
    int     statut;

	if (pid == -1) {
		return 1;
	} else if (pid == 0) {
        fd = dup2(fd1, fd);
        close(fd1);
        write(fd, "TEST\n", 5);
	} else 
        fd = 1;
    wait(&statut);
    return 0;
}*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>

int main(void)
{/*
    int fd_out;
    int save_stdout;

    fd_out = open("outfile.txt", O_CREAT | O_RDWR | O_APPEND, 0644);
    save_stdout = dup(STDOUT_FILENO);

    dup2(fd_out, STDOUT_FILENO);
    write(1, "oui\n", 4);

    dup2(save_stdout, STDOUT_FILENO);
    close(save_stdout);
    write(1, "non\n", 4);
    close(fd_out);*/
    char *str = "lol";
    char *tmp = str;
    str = "prout";
    printf("%s\n", tmp);
    printf("%s\n", str);
    return (0);
}
