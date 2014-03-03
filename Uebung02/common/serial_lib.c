#include "../vorlagen/uart.h"
#include <sys/io.h>
#include <stdio.h>
#include "serial_lib.h"

char is_byte_pending();
char receive_byte();

void setup_io_port(){
    if(ioperm(BASE_ADDR, 8, 1)){
        printf("ERROR in ioperm\n");
    }
}

char is_byte_pending(){
    return inb(BASE_ADDR + LSR) & DR;    
}

char receive_byte(){
    return inb(BASE_ADDR + RBR);
}
