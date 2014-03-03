#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "../common/serial_lib.h"

int main(){
    char * rx_pipe = "/tmp/ser_tx";
    char * tx_pipe = "/tmp/ser_rx";
    
    setup_io_port();

    unlink(rx_pipe);
    unlink(tx_pipe);

    if(mkfifo(rx_pipe, S_IRWXU)){ 
        printf("[Server]: ERROR creating rx pipe");
        return 1;
    }

    if(mkfifo(tx_pipe, S_IRWXU)){
        printf("[Server]: ERROR creating tx pipe");
        return 1;
    }

    int rx_fd = open(rx_pipe, O_RDWR);

    if(rx_fd==-1){
        printf("[Server]: ERROR opening rx pipe");
        return 1;
    }
    
    int tx_fd = open(tx_pipe, O_RDWR);

    if(tx_fd==-1){
        printf("[Server]: ERROR opening tx pipe");
        return 1;
    }
    
    char buf[42];
    int bytes_received = read(rx_fd, buf, sizeof(buf));
    if(bytes_received<=0){
        printf("[Server]: ERROR reading rx pipe");
        return 1;
    }


    printf("[Server]: %i bytes received\n", bytes_received);
    
    char serial_rx_buffer[10];
    for(int i=0; i<10; ++i){
        while(!is_byte_pending()){}
            serial_rx_buffer[i] = receive_byte();
    }

    int bytes_written = write(tx_fd, serial_rx_buffer, 10);
    if(bytes_written <= 0){
        printf("ERROR writing tx pipe\n");
        return 1;
    }

    printf("[Server]: %i bytes written\n", bytes_written);
    sleep(2);
    close(tx_fd);
    close(rx_fd);
    unlink(tx_pipe);
    unlink(rx_pipe);
}
