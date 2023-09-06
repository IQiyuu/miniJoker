/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgoubin <dgoubin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/06 11:11:21 by dgoubin           #+#    #+#             */
/*   Updated: 2023/07/07 11:11:47 by dgoubin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

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
}
