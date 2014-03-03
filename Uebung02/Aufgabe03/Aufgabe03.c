#include "../vorlagen/uart.h"
#include <sys/io.h>
#include <stdio.h>

#define BASE_ADDR 0x3f8

char is_byte_pending();
char receive_byte();

int main(){
    if(ioperm(BASE_ADDR, 8, 1)){
        printf("ERROR in ioperm\n");
    }
    
    while(1){
        if(is_byte_pending()){
        char in = receive_byte();
        putchar(in);
        fflush(stdout);
        }
    }


}

char is_byte_pending(){
    return inb(BASE_ADDR + LSR) & DR;    
}

char receive_byte(){
    return inb(BASE_ADDR + RBR);
}
