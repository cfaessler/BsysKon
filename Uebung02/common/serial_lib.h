#define BASE_ADDR 0x3f8

void setup_io_port();

//Blocking call
char receive_byte();

//Blocking call
void send_byte(char value);

char is_byte_pending();
char ready_to_send();
