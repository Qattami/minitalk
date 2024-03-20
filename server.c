/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:45:50 by iqattami          #+#    #+#             */
/*   Updated: 2024/03/20 05:05:40 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	b;
	static char	msg;

	if (signal == SIGUSR1)
		msg = (msg << 1) | 1;
	else if (signal == SIGUSR2)
		msg = (msg << 1);
	b++;
	if (b == 8)
	{
		write(1, &msg, 1);
		b = 0;
		msg = 0;
	}
}

int	main(void)
{
	int	id;

	id = getpid();
	ft_putnbr(id);
	write(1, "\n", 1);
	signal(SIGUSR2, handler);
	signal(SIGUSR1, handler);
	while (1)
		pause();
	return (0);
}
