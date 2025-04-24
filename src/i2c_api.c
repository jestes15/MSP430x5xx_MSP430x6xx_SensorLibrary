#include "include/i2c_api.h"

void i2c_init(uint8_t i2c_set) {
    UCB0CTLW0 |= UCSWRST;

    // switch (i2c_set) {
    //     case 0:
    //         // Set 0 consists of pins P3.0 (SDA) and P3.1 (SCL)
    //         break;
    //     case 1:
    //         // Set 1 consists of pins P4.1 (SDA) and P4.2 (SCL)
    // }
}
