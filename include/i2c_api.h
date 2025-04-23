#ifndef _I2C_API_
#define _I2C_API_

#include "msp430.h"

void i2c_init();
void i2c_write_byte();
void i2c_write_bytes();
void i2c_read_byte();
void i2c_read_bytes();

void i2c_isr(void);

#endif