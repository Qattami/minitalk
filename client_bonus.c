/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:40:05 by iqattami          #+#    #+#             */
/*   Updated: 2024/03/20 05:04:42 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send(int pid, char c)
{
	int	error;
	int	counter;

	error = 0;
	counter = 7;
	while (counter >= 0)
	{
		if ((c >> counter) & 1)
			error = kill(pid, SIGUSR1);
		else
			error = kill(pid, SIGUSR2);
		usleep(400);
		counter--;
		if (error == -1)
			ft_putstr("Error");
	}
}

void	done(int sig)
{
	if (sig == SIGUSR1)
		ft_putstr("sent succesfully \n");
	exit(1);
}

int	main(int ac, char **av)
{
	int		pid;
	char	*str;
	int		i;

	pid = 0;
	if (ac == 3)
	{
		i = 0;
		pid = atoi(av[1]);
		if (pid < 0 || pid > 2147483647)
		{
			ft_putstr("PID incorrect");
			exit(1);
		}
		str = av[2];
		while (str[i])
			send(pid, str[i++]);
		send(pid, '\0');
		signal(SIGUSR1, done);
		while (1)
			pause();
	}
	else
		(ft_putstr("invalide input"), exit(1));
	return (0);
}
