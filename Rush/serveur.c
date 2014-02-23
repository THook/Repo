
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>

void	sig_handler(int signal)
{
	if (signal == SIGINT)
		printf("ctrl + c\n");
}

int	main(void)
{
	pid_t	pid;
	pid_t	ret;

	if ((pid = fork()) > 0)
	{
		ret = getpid();
		printf("PID is %d\n", ret);
		wait(0);
	}
	else
	{
		while (1)
			wait(0);
		//si un flag de fin est reçu, ou bien que le mauvais nombre de caractères lus est retourné, utiliser la fonction kill dans le client.c
	}
	return (0);		
}

