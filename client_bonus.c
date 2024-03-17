/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iqattami <iqattami@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/16 22:40:05 by iqattami          #+#    #+#             */
/*   Updated: 2024/03/17 22:48:08 by iqattami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		{
			write(1, "(null)", 6);
			return (6);
		}
	while (s[i])
	{
		write(1, &s[i],1);
		i++;
	}
	return (i);
}
void send(int pid, char *str)
{
	int i;
    int error;
    int counter;
	static char c;

	i = 0;
    error = 0;
	while(str[i]+1)
	{
        counter = 7;
        c = str[i];
        while (counter >= 0)//0011 0101  0001 1010
        {
            if((c >> counter) & 1)
                error = kill(pid, SIGUSR1);
            else
                error =   kill(pid, SIGUSR2);
            usleep(100);
            counter--;
            if(error == -1)
                ft_putstr("Error");
        }
        i++;
	}
}
void done(int sig)
{
    (void)sig;
    ft_putstr("sent succesfully");
}

int main(int ac, char **av)
{
    int pid;
    char *str;
    pid = 0;
    if(ac == 3)
    {
        pid = atoi(av[1]);
        if(pid < 0 || pid > 2147483647)
        {
            ft_putstr("PID incorrect");
            return ;
        }
        signal(SIGUSR1,done);
        str = av[2];
        send(pid, str);
        signal(SIGUSR1,done);

    }
    else
        ft_putstr("invalide input");

    return (0);
}