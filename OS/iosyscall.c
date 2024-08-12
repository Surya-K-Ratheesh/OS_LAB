#include<stdio.h>
#include<stdlib.h>
#include <unistd.h>
#include<fcntl.h> //file control
#include<sys/types.h>
#include<sys/stat.h>

static char message[]="hai Hello world";

int main(){
    int fd;
    char buffer[80];
    fd=open("IOSytemCall_file.txt",O_RDWR|O_CREAT|O_EXCL,S_IREAD|S_IWRITE);
    
    if(fd!=-1){
        printf("IOSytemCall_file.txt opened for read/write access\n");
        write(fd,message,sizeof(message));
        lseek(fd,0l,0);

        if(read(fd,buffer,sizeof(message))==sizeof(message)){
            printf("\"%s\" was written to IOSytemCall_file.txt\n",buffer);
        }
        else{
            printf("\t Error reading IOSytemCall_file.txt\n");
        }    
    }
    else{
        exit(0);
    }    
}