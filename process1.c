#include  <stdio.h>
#include  <string.h>
#include  <sys/types.h>

#define   BUF_SIZE   100

void  main(void)
{
     pid_t  pid;
     
     int    i=0;
     char   buf[BUF_SIZE];

    fork();
fork();
     pid = getpid();



     while(1) {
     i++;
          sprintf(buf, "Hello World! from pid %d, value = %d\n", pid, i);
          write(1, buf, strlen(buf));


	int ca;
	for(ca=0; ca<50000000;ca++){}



     } 
}
