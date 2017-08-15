#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>

void MY_ISR(int num)
{
	printf("signal NUM :: %d\n", num);
	//signal(SIGINT, SIG_DFL);

}

int main()
{
	printf("PID : %d\n", getpid());
	printf("HAI........\n");
	/// Here changing the default behivour of SIGINT TO MY_ISR so afer this change SIGINT default behivour change
	signal(SIGINT, MY_ISR);
	
	while(1);
	return 0;
}
