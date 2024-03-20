/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:40:22 by iqattami          #+#    #+#             */
/*   Updated: 2024/03/20 05:17:09 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_sigaction(int signal, siginfo_t *info, void *str)
{
	static int	b;
	static char	msg;

	(void)str;
	if (signal == SIGUSR1)
		msg = (msg << 1) | 1;
	else if (signal == SIGUSR2)
		msg = (msg << 1);
	b++;
	if (b == 8)
	{
		write(1, &msg, 1);
		if (!msg)
		{
			usleep(400);
			kill(info->si_pid, SIGUSR1);
		}
		b = 0;
		msg = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &ft_sigaction;
	if (sigaction(SIGUSR1, &sa, NULL) < 0 || sigaction(SIGUSR2, &sa, NULL) < 0)
	{
		ft_putstr("Error");
		exit(1);
	}
	ft_putnbr(getpid());
	write(1, "\n", 1);
	while (1)
		pause();
	return (0);
}
