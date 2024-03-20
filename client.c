/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 04:51:34 by iqattami          #+#    #+#             */
/*   Updated: 2024/03/20 04:59:24 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void	send(int pid, char *str)
{
	int			i;
	int			error;
	int			counter;
	static char	c;

	i = 0;
	error = 0;
	while (str[i])
	{
		counter = 7;
		c = str[i];
		while (counter >= 0)
		{
			if ((c >> counter) & 1)
				error = kill(pid, SIGUSR1);
			else
				error = kill(pid, SIGUSR2);
			usleep(400);
			counter--;
			if (error == -1)
				write(1, "Error", 5);
		}
		i++;
	}
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;

	pid = 0;
	if (ac == 3)
	{
		pid = atoi(av[1]);
		if (pid < 0 || pid > 2147483647)
		{
			ft_putstr("PID incorrect");
			exit(1);
		}
		str = av[2];
		send(pid, str);
	}
	else
		ft_putstr("invalide input");
	return (0);
}
