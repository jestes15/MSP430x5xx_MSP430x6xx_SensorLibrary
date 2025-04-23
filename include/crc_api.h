#include "msp430.h"

void crc16_ba_nondma(uint16_t seed, uint8_t* data);
void crc16_ba_rb_nondma(uint16_t seed, uint8_t* data);
void crc16_ba_dma(uint16_t seed, uint8_t* data);
void crc16_ba_rb_dma(uint16_t seed, uint8_t* data);

void crc16_b_dma(uint16_t seed, uint8_t data);
void crc16_b_rb_dma(uint16_t seed, uint8_t data);

void crc16_wa_nondma(uint16_t seed, uint8_t* data);
void crc16_wa_rb_nondma(uint16_t seed, uint8_t* data);
void crc16_wa_dma(uint16_t seed, uint8_t* data);
void crc16_wa_rb_dma(uint16_t seed, uint8_t* data);

void crc16_w_dma(uint16_t seed, uint8_t data);
void crc16_w_rb_dma(uint16_t seed, uint8_t data);
