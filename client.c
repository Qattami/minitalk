
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void send(int pid, char *str)
{
	int i;
    int error;
    int len;
    int counter;
	static char c;

	i = 0;
    error = -1;
    len = strlen(str);
    
	while(i < len)
	{
        counter = 0;
        c = str[i];
        while (counter < 8)
        {
            if((c >> counter) & 1)
                error = kill(pid, SIGUSR2);
            else
              error =   kill(pid, SIGUSR1);
            usleep(400);
            counter++;
            if(error == -1)
                pirntf("error");
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
        str = av[2];
        send(pid, str);
    }

}