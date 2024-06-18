#include<stdlib.h>
#include<stdio.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>

int main(int argc,char* argv[])
{
        int source,n;
        char buf;
        int filesize;
        int i;
        if(argc!=2)
        {
                fprintf(stderr,"usage <source>");
                exit(-1);
        }
        if((source = open(argv[1],O_RDONLY))<0)
        {
                fprintf(stderr,"cant open source\n");
                exit(-1);
        }
        filesize = lseek(source,(off_t)0,SEEK_END);
        printf("Source file size in %d\n",filesize);
        for(i=filesize-1;i>=0;i--)
        {
                lseek(source,(off_t)i,SEEK_SET);
                if((n=read(source,&buf,1))!=1) //specifies number of bytes to read bro
                {
                        fprintf(stderr,"cant read 1 byte");
                        exit(-1);
                }
                printf("%c",buf);
        }close(source);
        return 0;
}
