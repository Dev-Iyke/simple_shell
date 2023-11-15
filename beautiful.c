#include <stdio.h>
#include <unistd.h>


/**
 * main - function that dispays the PID of a program
 * Return: always 0;
 */

int main(void)
{
	pid_t pid;
	pid_t ppid;

	ppid = getppid();
	printf("the ppid is %u\n", ppid);

	pid = getpid();
	if (pid == -1)
	{
		perror("unavailable");
		return (0);
	}

	printf("The PID of this program is:%u\n", pid);

	return (0);
}
