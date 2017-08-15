#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void MY_ISR(int num)
{
	printf("signal NUM :: %d\n", num);
	//signal(SIGINT, SIG_DFL);
	raise(9);
}

int main()
{
	printf("PID : %d\n", getpid());
	printf("HAI........\n");
	/// Here changing the default behivour of SIGINT TO MY_ISR so afer this change SIGINT default behivour change
	signal(SIGINT, MY_ISR);
	
	/// Pause will block the process and waiting for any signal onece get signal it will unblock
	pause();
	printf("BYE.............\n");
	while(1);
	return 0;
}
