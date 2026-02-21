// Hou Wai Yip 116322609
#include "MyBitManipulation.h"
#include <stdio.h>

/*
* Toggle the bit at position pos in num
*/
int ToggleBit(int num, int pos) {
   num ^= (1 << pos);
   return num;
}

/*
* Return the position of the most significant set bit
* Return -1 if num == 0
*/
int GetMSB(int num) {
   unsigned int shift = 1U << 31;
    int i;
    if (num == 0){
        return -1;
    }

    for(i = 0; i < 32; i++){
        if((num & shift) != 0){
            break;
        } else{
            shift >>= 1;
        }
    }
    return 31-i; 
}

/*
* Clear bits from start to end (inclusive)
*/
int ClearBitRange(int num, int start, int end) {
    if (start < 0 || end > 31 || start > end) {
        return num; 
    }
    int shift = 1 << start;
    int i = start; 
    while (i <= end){
        num &= ~shift;
        shift <<= 1;
        i++;
    }
    return num;
}

/*
* Rotate num to the left by d bits
*/
uint32_t RotateLeft(uint32_t num, int d) {
    uint32_t left = 1U << 31;
    uint32_t right = 1;
    int i = 0;
    while (i < d){
        if ((num & left) != 0){
            num ^= left;
            num <<= 1;
            num |= right;
        } else{
            num <<= 1;
        }
        i++;
    }
    return num;
}

/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
   int evenMask = 0xAAAAAAAA;
    int oddMask = 0x55555555;
    int evenBits = num & evenMask;
    int oddBits = num & oddMask;
    unsigned int uEvenBits = (unsigned int)evenBits >> 1; 
    oddBits <<= 1;
    return uEvenBits | oddBits;
}


// int main() {
//     // GetMSB    
//     printf("GetMSB(418302): %d\n", GetMSB(418302)); // Expected output: 18
//     printf("GetMSB(1892374): %d\n", GetMSB(1892374)); // Expected output: 20
//     printf("GetMSB(88): %d\n", GetMSB(88)); // Expected output: 6
    
//     // ClearBitRange
//     printf("ClearBitRange(51234, 3, 8): %d\n", ClearBitRange(51234, 3, 8)); // Expected output: 51202
//     printf("ClearBitRange(1048575, 5, 12): %d\n", ClearBitRange(1048575, 5, 12)); // Expected output: 1040415
//     printf("ClearBitRange(8493, 10, 2): %d\n", ClearBitRange(8493, 10, 2)); // Expected output: 8493
    
//     // RotateLeft
//     printf("RotateLeft(74921, 9): %u\n", RotateLeft(74921, 9)); // Expected output: 38359552
//     printf("RotateLeft(2587561053, 14): %u\n", RotateLeft(2587561053, 14)); // Expected output: 3273090702
//     printf("RotateLeft(3333333, 3): %u\n", RotateLeft(3333333, 3)); // Expected output: 26666664

//     // SwapOddEvenBits
//     printf("SwapOddEvenBits(7843210): %d\n", SwapOddEvenBits(7843210)); // Expected output: 12279365
//     printf("SwapOddEvenBits(43219876): %d\n", SwapOddEvenBits(43219876)); // Expected output: 23312216
//     printf("SwapOddEvenBits(2882400001): %u\n", SwapOddEvenBits(2882400001)); // Expected output: 1473175298

//     return 0;
// }

