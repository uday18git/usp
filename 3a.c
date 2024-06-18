#include<stdio.h> // printf, ,fprintf
#include<stdlib.h> // exit, exit_failure
#include<unistd.h>// unistd for fork execl
#include<sys/types.h> // for process control pid_t, waitpid
#include<sys/wait.h>
int main()
{
        const char* command = "ls";
        pid_t pid = fork(); //returns -1 on an error , 0 on success , child's pid for the parents process
        if(pid == -1)
        {
                perror("fork failed");
                return -1;
        }
        else if(pid == 0) // child
        {
                execl("/bin/sh","sh","-c",command , (char*) NULL);
                _exit(EXIT_FAILURE) ;
        }else // parent
        {
                int status;
                if(waitpid(pid,&status,0)==-1) // waits for child process to finish
                {
                        perror("waitpid failed");
                        return -1;
                }
                else
                {
                        printf("Command executed with exit status: %d\n",WEXITSTATUS(status));
                        return status;
                }
        }
}
