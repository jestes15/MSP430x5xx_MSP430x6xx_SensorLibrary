#include "msp430.h"

void init_crc16(uint16_t seed);
void calc_crc16_ba_nondma(uint8_t* data);
void calc_crc16rb_ba_nondma(uint8_t* data);
void calc_crc16_ba_dma(uint8_t* data);
void calc_crc16rb_ba_dma(uint8_t* data);
void calc_crc16_b(uint8_t dma);
void calc_crc16rb_b(uint8_t dma);