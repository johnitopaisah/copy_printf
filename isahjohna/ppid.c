#include <unistd.h>
#include <stdio.h>

int main(void)
{
	printf("Parent ID: %u\n", getppid());
	printf("Process ID %u\n", getpid());
	return (0);
}
