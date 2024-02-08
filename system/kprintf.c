#include <xinu.h>

#define UNGETMAX 10             /* Can un-get at most 10 characters. */
static unsigned char ungetArray[UNGETMAX];
unsigned int  bufp;

syscall swap(void) {
	if (bufp > 0)
		 for(int i= 1; i < bufp; i++)		
 			 ungetArray[i] = ungetArray[i-1];
	    bufp--;

	    return bufp;
}


syscall kgetc(void)
{
	    volatile struct ns16550_uart_csreg *regptr;
	    regptr = (struct ns16550_uart_csreg *)UART_BASE;
		// TODO: First, check the unget buffer for a character.    
		//       Otherwise, check UART line status register, and
		//       once there is data ready, get character c. 
		                 uchar c;
		                     c = NULL;		       
				     while(!kchekc());
		                             if (bufp > 0) {
		                                     c = ungetArray[0];
		                                             swap();
		                                                 } else {
		                                                         c = regptr -> rbr;
		                                                             }
		                                                                 return c;
		    
		                                                                 }
		    

/**
 * kcheckc - check to see if a character is available.
 * @return true if a character is available, false otherwise.
 */
syscall kcheckc(void)
{
    volatile struct ns16550_uart_csreg *regptr;
    regptr = (struct ns16550_uart_csreg *)UART_BASE;

    // TODO: Check the unget buffer and the UART for characters.

	return SYSERR;
}

/**
 * kungetc - put a serial character "back" into a local buffer.
 * @param c character to unget.
 * @return c on success, SYSERR on failure.
 */
syscall kungetc(unsigned char c)
{
    // TODO: Check for room in unget buffer, put the character in or discard.

    return SYSERR;
}

syscall kputc(uchar c)
{
    volatile struct ns16550_uart_csreg *regptr;
    regptr = (struct ns16550_uart_csreg *)UART_BASE;

    // TODO: Check UART line status register.
    //       Once the Transmitter FIFO is empty, send character c.

    return c;
}

syscall kprintf(const char *format, ...)
{
    int retval;
    va_list ap;

    va_start(ap, format);
    retval = _doprnt(format, ap, (int (*)(long, long))kputc, 0);
    va_end(ap);
    return retval;
}
