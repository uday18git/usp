#include<stdio.h>
#include<stdlib.h>
#include<signal.h>
#include<unistd.h>

void sigint_handler(int signum)
{
        printf("Caught SIGINE (signal  number %d). Now resetting to default actions. \n",signum);
        fflush(stdout);
        struct sigaction sa;
        sa.sa_handler = SIG_DFL;
        sa.sa_flags=0;
        sigemptyset(&sa.sa_mask);
        if(sigaction(SIGINT,&sa,NULL)==-1)
        {
                perror("sigaction");
                exit(EXIT_FAILURE);
        }
}
int main()
{
        struct sigaction sa;
        sa.sa_handler = sigint_handler;
        sa.sa_flags=0;//no flags
        sigemptyset(&sa.sa_mask);
        if(sigaction(SIGINT,&sa,NULL)==-1)
        {
                perror("sigaction");
                exit(EXIT_FAILURE);
        }
        printf("PRess ctrl to trigger sigint,after the first c ,the default action will be resetted\n");        while(1){
                pause();
        }
        return 0;
}
