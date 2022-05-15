#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/resource.h>


void ViewRUsage(struct rusage *pru);
int main()
{
    pid_t cpid = fork();

    if(cpid == -1)
    {
        perror("error fork");
        return 0;
    }

    if(cpid>0)
    {
        printf("<parent> fork child pid:%u\n",cpid);
        int rvalue = 0;
        struct rusage ru;
        wait3(&rvalue,0, &ru);
        ViewRUsage(&ru);
    }
    else
    {
        printf("<child> pid:%d \n",getpid());
        int i=0;
        for(i=0;i<100000;i++)
        {
            fprintf(stderr,".");
        }
    }
    return 0;
}
void ViewRUsage(struct rusage *pru)
{
    printf("\n=== pid rusage info ===\n");
    struct timeval *tv = &(pru->ru_utime);
    printf("user CPU time used [%ld]sec [%d]usec\n", tv->tv_sec,tv->tv_usec );
    tv = &(pru->ru_stime);
    printf("system CPU time used [%ld]sec [%d]usec\n", tv->tv_sec,tv->tv_usec );
}
