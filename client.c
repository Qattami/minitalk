
#include <signal.h>
#include <stdio.h>


void send(int pid, char *str)
{
	int i;
    int len;
    int counter;
	static char c;

	i = 0;
    len = ft_strlen(str);
    
	while(i < len)
	{
        counter = 0;
        c = str[i];
        while (counter < 8)
        {
            if((counter >> 1) & c)
                kill(pid, SIGUSR2);
            else
                kill(pid, SIGUSR1);
            sleep(1000);
            counter++;
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
        pid = ft_atoi(av[1]);
        str = av[2];
        send(pid, str);
    }

}