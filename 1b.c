#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main()
{
        int fd = open("file.txt",O_RDONLY);
        if(fd ==-1)
        {
                perror("Error opening file");
                return 1;
        }
        pid_t pid = fork();
        if(pid==-1)
        {
                perror("Error forking");
                close(fd);
                return 1;
        }
        if(pid==0)
        {
                // child process pid==0 means
                char buf[11];
                read(fd,buf,10);
                buf[10] = '\0';
                printf("Child read:%s\n",buf);
                close(fd);
        }else
        {
                wait(NULL); // waiting for child to finish
                char buf[11];
                read(fd,buf,10);
                lseek(fd, 0, SEEK_SET);
                buf[10] = '\0';
                printf("PArent read: %s\n",buf);
                close(fd);
        }return 0;
}
