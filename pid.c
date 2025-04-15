#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - prints the PID of the parent process
 * Return: 0 if sucess
 */

int main(void)
{
	pid_t ppid;

	ppid = getppid();

	printf("%u\n", ppid);

	return (0);
}

