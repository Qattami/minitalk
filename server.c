#include<unistd.h>
#include <stdio.h>
#include <signal.h>

void handler(int signal)
{
	static int i;
	static int b;

	i = 0;
	b = 0;
	if(signal == SIGUSR1)
	{
		i |= (1 << b);
	}
	b++;
	if(b == 8)
	{
		b = 0;
		i = 0;
	}

}
int main()
{
	printf("pid of server==> %d",getpid());
	while(1);
	{
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		sleep(500);
	}

 return 0;
}
