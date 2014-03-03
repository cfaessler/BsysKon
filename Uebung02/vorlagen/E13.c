// E13.c: Test program for "Serial Port" Register Access
// =====================================================
//
// This program can be run on a PC under Linux.
// This driver uses the serial port to demonstrate 
// input/output on user-level (requires root privilege!).
//
// *** Sample solution for E1.3 programming assignment
//
// E. Glatz / 12-JAN-2009

#include <sys/io.h>
#include <stdio.h>


int main () 
{
   unsigned char invalue; // Note: an int would be ok, too. But should be intialized to 0.
   unsigned int outvalue; // Note: do not use a char: scanf() always inputs 4 Byte for a %x

   // Set io permission for register SCR of device "ttyS0" (requires root privilege)
   if (ioperm(0x3f8+7, 1, 1)) {
      printf ("ERROR: ioperm() failed. Check if you have root privileges.\n");
      return 1;
   }
   printf("Please enter 2-digit hex number to write to SCR: 0x");
   if (!scanf ("%2x", &outvalue)) {
      printf ("\nERROR: invalid entry format!\n");
      ioperm(0x3f8+7, 1, 0);
      return 1;
   }
   // Output byte to SCR
   outb(outvalue, 0x3f8+7);
   // Read value back from SCR
   invalue = inb(0x3f8+7);
   printf("Value read from SCR (port addr. 0x3f8+7): 0x%2x\n", invalue);
   // Reset io permission
   ioperm(0x3f8+7, 1, 0);
   return 0;
}
