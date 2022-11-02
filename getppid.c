#include "main.h"

int main(void)
{	pid_t ppid = getppid();
	pid_t pid = getpid();
	printf("the ppid is %d and the pid is %d\n", ppid, pid);
	
	
	return (0);
}
