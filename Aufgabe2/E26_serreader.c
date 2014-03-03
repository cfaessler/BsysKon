// E26_serreader.c: Test client for receive 
// ========================================
//
// Receives data through pipe ser_rx and prints it
// to console. 
//
// This program can be run on a PC under Linux.
//
//	Prerequisites:
//	- directory /tmp exists
//
// *** Sample program for an applicatio for E2.6 programming assignment
//
// E. Glatz / 16-JAN-2009
//


#include <sys/io.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>


#pragma optimization_level 2

int main ()
{
   int fdrx;
	char in_text[200];

   // Open named pipe

   // Wait for data from server process
	char * rx_name = "/tmp/ser_rx";
   fdrx = open (rx_name, O_RDWR);
   if (fdrx==-1) {
      printf("ERROR: open for %s failed\n", rx_name);
      return 1;
   }
   printf("Waiting for receive data...\n");
	
	while(1) {
	   // Read text from pipe
		ssize_t reads;
	   if ((reads=read(fdrx, in_text, sizeof(in_text))) == 0) {
	      printf("ERROR: 0 byte result of read on %s\n", rx_name);
	      return 1;
	   }
		in_text[reads]=0; // Add terminating zero for printf()
	   printf("%s", in_text);
		fflush(stdout);	// Force immediate console output
	}
	// Now: dead code
   close(fdrx);
   printf("All done.\n");
   return 0;
}
