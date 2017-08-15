#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <signal.h>



int main()
{
	printf("PID : %d\n", getpid());
	printf("HAI........\n");

	/// alram defult behivour is not be terminate even though program is in while loop
	alarm(5);
	while(1);
	return 0;
}
