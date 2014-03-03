/**

	uart.h
	======

	Register address and bitmask definitions for a serial device
	of type 16550.

	16. Jan. 2009 / E. Glatz


**/


// Define addresses relativ to base address
// chosen register names are depicted from 16550 data sheet

#define RBR     0   // Receiver Buffer Register (read only)
#define THR     0   // Transmitting Holding register (write only)
#define IER     1   // Interrupt Enable Register
#define IIR     2   // Interrupt Ident Register (read only)
#define FCR     2   // FIFO Control Register (write only)
#define LCR     3   // Line Control Register
#define MCR     4   // Modem Control Register
#define LSR     5   // Line Status Register
#define MSR     6   // Modem Status Register
#define SCR     7   // Scratch Register
#define DLL     0   // Divisor Latch (LS)
#define DLM     1   // Divisor Latch (MS)


// Bitmasks for some register


// IER Interrupt Enable Register
#define ERBFI   0x01    // Enable Received Data Available Interrupt
#define ETBEI   0x02    // Enable Transmitter Holding Register Empty Interrupt
#define ELSI    0x04    // Enable Receiver Line Status Interrupt
#define EDSSI   0x08    // Enable Modem Status Interrupt

// FCR FIFO Control Register
#define FENA    0x01    // FIFO enable
#define RRFIFO	 0x02		// Receiver FIFO resset
#define RTFIFO  0x04		// Transmitter FIFO reset

// LCR Line Control Register
#define WLS0    0x01    // Word Length Select Bit 0
#define WLS1    0x02    // Word Length Select Bit 1
#define STB     0x04    // Number of Stop Bits
#define PEN     0x08    // Parity Enable
#define EPS     0x10    // Even Parity Select
#define DLAB    0x80    // Divisor Latch Access Bit

// MCR Modem Control Register
#define DTR     0x01    // Data Terminal Ready
#define RTS     0x02    // Request to Send
#define OUT2    0x08    // Out2: Enable/Disable UART

// LSR Line Status Register
#define DR      0x01    // Data Ready
#define THRE    0x20    // Transmitter Holding Register
#define TEMT    0x40    // Transmitter Empty

// MSR Modem Status Register
#define CTS     0x10    // Clear To Send
#define DSR     0x20    // Data Set Ready
#define RI      0x40    // Ring Indicator
#define DCD     0x80    // Data Carrier Detect

// Interrupt Ident Register (IIR)
// (these masks can be used to identify interrupt causes)
#define INT_NONE    0x01    // kein Interrupt
#define INT_RLS     0x06    // Receiver Line Status Interrupt
#define INT_RDA     0x04    // Read Data Available Interrupt
#define INT_CTI     0x0C    // Character Timeout Indication Interrupt
#define INT_THRE    0x02    // Transmitter Holding Register Empty Interrupt
#define INT_MODEM   0x00    // Modem Status Interrupt


#define BPSBase     115200 // Maximal data rate supported by this UART

//End of uart.h
