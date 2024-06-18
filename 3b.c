#include<stdio.h>
#include<unistd.h>
#include<fcntl.h> // file control options
#include<dirent.h> // directory entry
#include<time.h> // time and date functions.
#include<sys/stat.h> // data returned by the stat function

int main()
{
        struct dirent *dir; // pointer to directory entry structure, this is a pointer because readdir returns a pointer to a dynamically managed directory entry.
        struct stat mystat; // a structure to hold info about the file
        DIR *dp; // a pointer to the directory stream
        dp = opendir("."); // opens the current directory "." represents the current directory
        if(dp)
        {
                while(dir = readdir(dp)){
                        stat(dir->d_name,&mystat);  // inode number, file mode , uid of file owner, group id , time of last access , name of file or directiry
                        printf("%ld %o %d %d %s %s\n",mystat.st_ino,mystat.st_mode,mystat.st_uid,mystat.st_gid,ctime(&mystat.st_atime),dir->d_name);
                }
        }
}
