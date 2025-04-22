#include "msp430f5529.h"

#include <stdint.h>
#include <stdio.h>

/* Include the Qmath header file. */
#include "QmathLib.h"

float calculate_temp(__uint16_t, float lsb);

int main(void)
{
    /* Disable WDT. */
    WDTCTL = WDTPW | WDTHOLD;


    return 0;
}

float calculate_temp_12b(__uint16_t temp_dd_fmt, float prec) {
#ifdef USE_FIXED_POINT_QMATH
    _q4 data, lsb, res, neg1;
    __uint16_t twos_compl;

    // Check for negative temperature value
    if ((temp_dd_fmt & 0x800) == 0x800) {
        // Convert to twos compliment
        twos_compl = ~temp_dd_fmt + 1;
        neg1 = _Q4(-1);
    }
    else {
        // If the number is not negative, just assign to twos_compl
        twos_compl = temp_dd_fmt;
        neg1 = 0;
    }

    // Convert temperature from digital data format to fixed point _q4
    data = _Q4(twos_compl);
    lsb = _Q4(prec);

    // Multiply the incoming data and LSB value together
    res = _Q4mpy(data,  lsb);

    // If the number is negative, we must multiply by -1
    if (neg1)
        res = _Q4mpy(res,  neg1);

    // Return the calculated value in floating point format
    return _Q4toF(res);
#else
    float emul_fp_res;

    if ((temp_dd_fmt & 0x800) == 0x800)
        emul_fp_res = ((~temp_dd_fmt & 0xFFF) + 1) * prec * -1;
    else
        emul_fp_res = temp_dd_fmt * prec;
    
    return emul_fp_res;
#endif
}