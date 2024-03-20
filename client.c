
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "minitalk.h"

void send(int pid, char *str)
{
	int i;
    int error;
    int counter;
	static char c;

	i = 0;
    error = 0;
	while(str[i])
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
                write(1, "Error",5);
        }
        i++;
	}
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
            exit(1) ;
        }
        str = av[2];
        send(pid, str);
    }
    else
        ft_putstr("invalide input");

    return (0);
}