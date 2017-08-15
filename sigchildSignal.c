#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>


/// Zombie Process means Child is terminate but still Parent is alive it called Zombie Process
/// When child is terminated at that time parent process recevie SIGCHLD signal . it can handle by signal handler
void MY_ISR(int num)
{
	printf("signal NUM :: %d\n", num);

	wait(0);
}


int main()
{
int s = 0;
	if(fork() == 0){
		  printf("CHILD :: PID : %d\n", getpid());
		  sleep(4);
	}else{
		  printf("PID : %d\n", getpid());
		  printf("HAI........\n");
		  signal(SIGCHLD, MY_ISR);
		  sleep(10);
		  printf("AFTEr sleep in Prent\n");

	}
	while(1);
	return 0;
}
