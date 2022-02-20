#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<errno.h>
#include<fcntl.h>
#include<time.h>
int main(int argc,char *argv[]){
        char *myfifo="myfifo";
  mkfifo(myfifo,0666);
  int arr[5];  
        int fd=open("myfifo",O_RDONLY);
        if(fd==-1){
  return 1;
  }
       if( read(fd,&arr,sizeof(int)*5)==-1){
       
                return 3;
       }
       printf("Received\n");  
       close(fd);
      int sum=0;  
          int i=0; 
    for(i=0;i<5;i++){
      sum+=arr[i];
    }
    printf("Sum is: %d\n",sum);

  return 0;
}
