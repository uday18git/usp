#include <stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include <time.h>
#include <utime.h>
void print_file_times(const char* filename)
{
        struct stat statbuf; // struct to hold information 
        if(stat(filename,&statbuf)<0) //stat function to get information
        {
                perror("stat error");
                return;
        }
        printf("File: %s\n",filename); 
        printf("Access time: %s",ctime(&statbuf.st_atime));
        printf("Modification time: %s\n",ctime(&statbuf.st_mtime));
}
int main(int argc,char* argv[])
{
        struct stat statbuf; // to hold file info of the source
        struct utimbuf timebuf; // to hold access and mod info
        print_file_times(argv[2]); 
        if(stat(argv[1],&statbuf)<0)
        {
                perror("stat error");
                exit(EXIT_FAILURE);
        }
        timebuf.actime=statbuf.st_atime;
        timebuf.modtime=statbuf.st_mtime;
        if(utime(argv[2],&timebuf)<0)
        {
                perror("utime error on destinatino file");
                exit(EXIT_FAILURE);
        }
        print_file_times(argv[2]);
        return 0;
}
