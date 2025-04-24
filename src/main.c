#include "include/main.h"

// Clock speed is 25 MHz
int main(void)
{
    /* Disable WDT. */
    WDTCTL = WDTPW | WDTHOLD;

    // Disable interrupts
    __disable_interrupt();

    // Put USCI peripheral into reset
    UCB1CTL1 |= UCSWRST;

    // Configure UCB1CTL0
    UCB1CTL0 &= ~(UCA10 | UCSLA10 | UCMM);
    UCB1CTL0 |= UCMODE_3;

    // Configure UCB1CTL1
    UCB1CTL1 |= UCSSEL0;

    // Set clock prescaler values for Baud Rate
    UCB1BR0 = (uint8_t)250;
    UCB1BR1 = (uint8_t)0;

    // Set own I2C address
    UCB1I2COA &= ~UCGCEN;
    UCB1I2COA &= ~(UCOA6 | UCOA5 | UCOA4 | UCOA3 | UCOA2 | UCOA1 | UCOA0);
    
    // Setup interrupts
    UCB1IE &= ~(UCALIE | UCSTTIFG | UCSTPIFG);
    UCB1IE |= (UCNACKIE | UCTXIE | UCRXIE);

    // Clear pending interrupts
    UCB1IFG &= ~(UCNACKIFG | UCALIFG | UCSTPIFG | UCSTTIFG | UCTXIFG | UCRXIFG);

    __enable_interrupt();

    UCB1CTL1 &= ~UCSWRST;

    calculate_temp_12b(0x453, 0.0625);

    return 0;
}

#pragma vector = USCI_B1_VECTOR
__interrupt void i2c_isr(void) {
    uint16_t UCB1IV_loc = UCB1IV;

    if (UCB1IV_loc == BIT2) {
        // Service No ACK
    }
    else if (UCB1IV_loc == BIT5) {
        // Service data received
    }
    else if (UCB1IV_loc == BIT6) {
        // Add more data from I2C data buffer
    }
}
