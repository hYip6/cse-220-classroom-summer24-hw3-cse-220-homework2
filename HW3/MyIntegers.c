// Hou Wai Yip 116322609
#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>

unsigned int twoPower(int power){
    return 1U << power;
}

void repr_convert(char source_repr, char target_repr, unsigned int repr) {
    bool convertTwo = false;
    bool convertToTwo = false;
    int conversion = 0;
    
    if ((source_repr != '2' && source_repr != 'S') || (target_repr != '2' && target_repr != 'S')) {
        printf("error\n");
        return;
    }
    if (source_repr == '2' && target_repr == 'S' && repr == 0x80000000) {
        printf("undefined\n");
        return;
    }     
    if (source_repr == '2'){
        convertTwo = true;
    }
    if (target_repr == '2'){
        convertToTwo = true;
    }

    if (convertTwo){
        int pointer = 1 << 31;
        for (int i = 0; i < 32; i++){
            if (i == 0){
                conversion += -(twoPower(31-i) * ((repr >> (31 - i)) & 1));
            } else{
                conversion += (twoPower(31-i) * ((repr >> (31 - i)) & 1));
            }
        }
    } else{
        bool isNegative = false;
        if ((repr >> 31) & 1){
            isNegative = true;
        }
        
        int temp = ((repr << 1) >> 1); 
        
        if (isNegative){
            conversion = -temp;
        } else{
            conversion = temp;
        }
    }
    
    if (convertToTwo){
        if (conversion){
            printf("%08x\n", conversion);
            return;
        } else{
            int temp = ~conversion;
            temp += 1;
            printf("%08x\n", temp);
            return;
        }
    } else{
        if (conversion < 0){
            unsigned int temp = (1U << 31) | (unsigned int)(-conversion);
            printf("%08x\n", temp);
            return;
        } else{
            printf("%08x\n", conversion);
            return;
        }
    }
}


// int main(){
//     repr_convert('S', '2', 0x8badf00d); // expected: f4520ff3
//     repr_convert('2', 'S', 0xc0ffee00); // expected: bf001200
//     repr_convert('S', '2', 0x01234567); // expected: 01234567
//     repr_convert('2', 'S', 0xffffff00); // expected: 80000100
//     repr_convert('S', '2', 0x800000ff); // expected: ffffff01
//     repr_convert('S', '2', 0xffffffff); // expected: 80000001
//     repr_convert('2', 'S', 0x7fffffff); // expected: 7fffffff
//     repr_convert('2', '2', 0x99887766); // expected: 99887766
//     repr_convert('S', 'S', 0xf000000f); // expected: f000000f
//     repr_convert('A', '2', 0x12345678); // expected: error
    
//     return 0;
// }
