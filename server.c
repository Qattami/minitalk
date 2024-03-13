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
	printf("%c", (char)i); 
	if(b == 8)
	{
		b = 0;
		i = 0;
	}

}
int main()
{
	int id;
	id = getpid();
	printf("pid of server==> %d",id);
		signal(SIGUSR1, handler);
		signal(SIGUSR2, handler);
		
		while(1)
			pause();
	

 return 0;
}
