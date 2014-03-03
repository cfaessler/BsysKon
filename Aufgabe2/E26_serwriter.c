// E26_serwriter.c: Test program for transmission via serial driver 
// ===============================================================
//
// Transmits a given text through pipe ser_tx and prints a short 
// message to console when don.
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


int main ()
{
    char out_text[] = "Prognosen bis morgen Freitagabend\n \
    Alpennordseite, Wallis und Graubuenden: Heute Nachmittag zuerst noch meist sonnig, \
    In der Folge zuerst im Westen, dann auch im Osten allmaehliche Bewoelkungszunahme. \
    Morgen Vormittag in den zentralen und oestlichen Landesteilen noch groessere Aufhellungen, \
    sonst veraenderlich und da und dort einige Regenschauer. \
    Am Alpenkamm bereits heute Nachmittag aus Sueden meist bewoelkt und spaeter etwas Regen. \
    Temperaturen heute um 27, in der Nacht zwischen 13 und 16 Grad. \
    Tageshoechsttemperaturen morgen bei 23, bei Foehn noch bei 26 Grad. \
    Nullgradgrenze auf 3700 Metern. In den Bergen maessiger bis starker Suedwind, \
    morgen Nachmittag nachlassend. In den Alpentaelern bis morgen Vormittag noch zeitweise Foehn. \
    Alpensuedseite: Bedeckt und von heute Abend bis morgen Nachmittag haeufig Regen, \
    in der Nacht zum Teil ergiebig. Morgen Abend wahrscheinlich trocken. \
    Tageshoechsttemperaturen jeweils bei 20 Grad.\n";

   int fdtx;

   // Open named pipe
	char * tx_name = "/tmp/ser_tx";
   fdtx = open (tx_name, O_RDWR);
   if (fdtx==-1) {
      printf("ERROR: open for %s failed\n", tx_name);
      return 1;
   }

	int textlen = strlen(out_text);	
	ssize_t written;
   if (written=write(fdtx, out_text, textlen+1) < 1) {
      printf("ERROR: could not write text to %s\n", tx_name);
      return 1;
   } else {
        printf("Number of bytes written: %d\n", written);
	}

   close(fdtx);
   printf("All done.\n");
   return 0;
}
