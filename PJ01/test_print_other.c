#include <linux/unistd.h>
#include <sys/syscall.h>
#include <sys/types.h>
#include <stdio.h>

#define __NR_print_other 339

int main(int argc, char *argv[]) {

	int findPID;
	printf("Enter a PID:  ");
	scanf("%d", &findPID);
	pid_t pid = findPID;


	syscall(__NR_print_other,findPID);


	return 0;
}
