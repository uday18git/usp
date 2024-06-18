#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include <sys/wait.h>
int main()
{
        pid_t child_pid;
        child_pid = fork();
        if(child_pid<0)
        {
                perror("fork failed");
                exit(1);
        }else if(child_pid==0)
        {
                printf("child process (PID: %d) started\n",getpid());
                sleep(2);
                printf("Child process (PID: %d) exiting\n",getpid());
                exit(0);
        }else{
                int status;
                pid_t wait_pid=waitpid(child_pid,&status,0);
                if(wait_pid==-1){
                        perror("Wait/waitpid failed");
                        exit(1);
                }
                printf("Parent process (PID: %d) waiting for child (PID: %d)\n",getpid(),child_pid);
                return 0;
        }
}
