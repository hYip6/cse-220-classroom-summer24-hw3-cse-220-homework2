// Hou Wai Yip 116322609
#include "Myfloat.h"
#include <stdio.h>

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   unsigned int pointer = 1U<<31; 
    if (sign_bit == 1){
        f |= pointer;
    }
    pointer >>= 1;
    for (int i = 0; i < 8; i++){
        unsigned int temp = 1 << (7-i); 
        if ((temp & exponent) != 0){
            f |= pointer;
        }
        pointer >>= 1;
    }
    for (int i = 0; i < 23; i++){
        unsigned int temp = 1 << (22-i); 
        if ((temp & fraction) != 0){
            f |= pointer;
        }
        pointer >>= 1;
    }

   return *(float *)&f;
}


// int main() {
//     printf("f=%g\n", construct_float_sf(0x01, 0x82, 0x240000)); // -10.25
//     printf("f=%g\n", construct_float_sf(0x00, 0x82, 0x400000)); // 12.0
//     printf("f=%g\n", construct_float_sf(0x01, 0x7C, 0x200000)); // -0.15625
//     printf("f=%g\n", construct_float_sf(0x00, 0x85, 0x480000)); // 100.0
//     printf("f=%g\n", construct_float_sf(0x00, 0x80, 0x490000)); // 3.140625
//     printf("f=%g\n", construct_float_sf(0x01, 0x84, 0x280000)); // -42.0
//     printf("f=%g\n", construct_float_sf(0x00, 0x00, 0x000000)); // 0
//     printf("f=%g\n", construct_float_sf(0x01, 0x7E, 0x400000)); // -0.75
//     printf("f=%g\n", construct_float_sf(0x00, 0x82, 0x080000)); // 8.5
//     printf("f=%g\n", construct_float_sf(0x00, 0x7F, 0x000000)); // 1.0

//     return 0;
// }
