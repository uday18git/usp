#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/wait.h>
int main()
{
        pid_t pid;
        int status;
        printf("Parent process ID: %d\n",getpid());
        pid= fork();
        if(pid==0){
                printf("Child process id:%d, parent proces id: %d\n",getpid(),getppid());
                execl("/bin/ls","ls",NULL);
                perror("execl");
                exit(EXIT_FAILURE);
        }else{
                printf("Praent process waiting for child (PID: %d) to exit... \n",pid);
                waitpid(pid,&status,0);
        }
        return 0;
}
