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
	pid_t  pid;
	int    i=0;
	char   buf[BUF_SIZE];
 
	/* fork another process */

	pid = fork();
	pid = fork();
	if (pid < 0) { /* error occurred */
		fprintf(stderr, "Fork Failed");
		exit(-1);
	}
	else if (pid == 0) { /* child process */
		
		
		while(1) {
			i++;
			sprintf(buf, "Hello World! from pid %d, value = %d\n", getpid(), i);
			write(1, buf, strlen(buf));
			waitFor(1);
		} 
	}
	else { /* parent process */
		/* parent will wait for the child to complete */
		wait (NULL);
		printf ("Child Complete");
		exit(0);
	}
}

