#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<unistd.h>

 int main()
{
    char c;
    int waitCounter = 4;
    int i;
    pid_t pid;
    pid_t pid1;
    pid_t pid2;
    pid_t pid3;

    for(i = 0; i<=4; i++)
    {
        //fork another process
        pid = fork();

        //if the pid is negative, error
            if(pid < 0 )
            {
                fprintf(stderr, "Fork Failed");
                exit(-1);
            }
            //if pid is 0, I am a child process
            if(pid == 0)
            {
             int num = i;
             char buf[5];

             sprintf(buf, "%d", i);

              
            }

    }

    //wait for child process to complete
    while(waitCounter >0)
    {
        wait(NULL);
        waitCounter--;
    }

          printf("\nChild processes Complete.\n");
           printf("Parent pid: ");
           printf("%d", getpid());
           exit(0);


    return 1;
}
