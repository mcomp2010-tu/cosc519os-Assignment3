#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>
#include <time.h>


#define   BUF_SIZE   100
int retTime = 0;

void waitFor (unsigned int secs) {
    retTime = time(0) + secs;     // Get finishing time.
    while (time(0) < retTime);    // Loop until it arrives.
}

int main()
{
	pid_t pid;
	int i = 0;
		char   buf[BUF_SIZE];
		
	for(i = 0; i < 4; i++) {
		pid = fork();
		if(pid < 0) {
			printf("Error");
			exit(1);
		} else if (pid == 0) {
			sprintf(buf, "Hello World from child! from pid %d, value = %d\n", getpid(), i);
			write(1, buf, strlen(buf));
			exit(0); 
		} else  {
			wait(NULL);
			sprintf(buf, "Hello World from Parent ! from pid %d, value = %d\n", getpid(), i);
			write(1, buf, strlen(buf));
		}
	}
}

