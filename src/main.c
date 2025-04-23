#include "include/main.h"

// Clock speed is 25 MHz
int main(void)
{
    /* Disable WDT. */
    WDTCTL = WDTPW | WDTHOLD;

    calculate_temp_12b(0x453, 0.0625);

    return 0;
}
