// E25_clnt.c: Sample application accessing the user-space driver 
// =============================================================
//
// Sample application implementing the client side that sends and 
// receives data from a user-space driver. This program first asks the
// user to enter a character that is sent through pipe ser_tx to the server.
// Then, this program waits at the pipe ser_rx for data that is written
// to the console on reception.
//
// This program can be run on a PC under Linux.
//
//	Prerequisites:
//	- directory /tmp exists
//
// *** Sample program for an applicatio for E2.5 programming assignment
//
// E. Glatz / 16-JAN-2009


#include <sys/io.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


int main ()
{
   int fdtx, fdrx;
	char out_text[200], in_text[200];

   // Open named pipe
	char * tx_name = "/tmp/ser_tx";
   fdtx = open (tx_name, O_RDWR);
   if (fdtx==-1) {
      printf("ERROR: open for %s failed\n", tx_name);
      return 1;
   }
   // Ask user for a character and write it to tx pipe
   printf("Please enter a text to be sent: ");
   if (!scanf ("%s", out_text)) {
      printf ("\nERROR: invalid entry format!\n");
      return 1;
   }
	int textlen = strlen(out_text);	
   if (write(fdtx, out_text, textlen+1) < 1) {
      printf("ERROR: could not write text to %s\n", tx_name);
      return 1;
   }

   // Wait for answer from server process
	char * rx_name = "/tmp/ser_rx";
   fdrx = open (rx_name, O_RDWR);
   if (fdrx==-1) {
      printf("ERROR: open for %s failed\n", rx_name);
      return 1;
   }
   printf("Waiting for reply of server (server sends when 10 chars are ready)\n");
   // Read text from pipe
   if (read(fdrx, in_text, sizeof(in_text)) == 0) {
      printf("ERROR: 0 byte result of read on %s\n", rx_name);
      return 1;
   }
   printf("Read back text obtained from server is %s\n", in_text);
   close(fdtx);
   close(fdrx);
   printf("All done.\n");
   return 0;
}
