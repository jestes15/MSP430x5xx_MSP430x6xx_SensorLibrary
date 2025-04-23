#include "include/main.h"

// Clock speed is 25 MHz
int main(void)
{
    /* Disable WDT. */
    WDTCTL = WDTPW | WDTHOLD;

    // Put USCI peripheral into reset
    UCB1CTL1 |= UCSWRST;

    // Clear bits 7, 6, and 5
    // Clearing bit 7 corresponds to the MSP430's own address being a 7-bit address
    // Clearing bit 6 corresponds to the slave's address being a 7-bit address
    // Clearing bit 5 corresponds a single master enviroment
    UCB1CTL0 &= ~(BIT7 | BIT6 | BIT5);

    // Set bits 2 and 1
    // Setting these bits sets the USCI mode to I2C
    UCB1CTL0 |= (BIT2 | BIT1)

    // 

    calculate_temp_12b(0x453, 0.0625);

    return 0;
}
