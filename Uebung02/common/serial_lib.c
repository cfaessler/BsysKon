#include "../vorlagen/uart.h"
#include <sys/io.h>
#include <stdio.h>
#include "serial_lib.h"

void setup_io_port(){
    if(ioperm(BASE_ADDR, 8, 1)){
        printf("ERROR in ioperm\n");
    }
}

char is_byte_pending(){
    return inb(BASE_ADDR + LSR) & DR;    
}

char receive_byte(){
    while(!is_byte_pending()){};
    return inb(BASE_ADDR + RBR);
}

void send_byte(char value){
    while(!ready_to_send()){};
    outb(value, BASE_ADDR + THR);
}

char ready_to_send(){
    return inb(BASE_ADDR + LSR) & TEMT;
}

