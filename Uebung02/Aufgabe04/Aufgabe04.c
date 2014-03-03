#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main(){
    char * rx_pipe = "input";
    char * tx_pipe = "output";
    
    if(mkfifo(rx_pipe, S_IRWXU)){ 
        printf("ERROR creating rx pipe");
    }

    if(mkfifo(tx_pipe, S_IRWXU)){
        printf("ERROR creating tx pipe");
    }

    int rx_fd = open(rx_pipe, O_RDWR);

    if(rx_fd==-1){
        printf("ERROR opening rx pipe");
    }
    
    int tx_fd = open(tx_pipe, O_RDWR);

    if(tx_fd==-1){
        printf("ERROR opening tx pipe");
    }
    
    char buf[42];
    int bytes_received = read(rx_fd, buf, sizeof(buf));
    if(bytes_received<=0){
        printf("ERROR reading rx pipe");
    }

    int bytes_written = write(tx_fd, buf, bytes_received);
    if(bytes_written<=0){
        printf("ERROR writing tx pipe");
    }

}
