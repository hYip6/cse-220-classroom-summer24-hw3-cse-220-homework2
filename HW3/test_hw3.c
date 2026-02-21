#include <criterion/criterion.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"

/* =========================
 * PART 1: Bit Manipulation
 * ========================= */

Test(ToggleBit, examples) {
    cr_assert_eq(ToggleBit(9, 0), 8);
    cr_assert_eq(ToggleBit(9, 3), 1);
}

Test(GetMSB, examples) {
    cr_assert_eq(GetMSB(18), 4);
    cr_assert_eq(GetMSB(0), -1);
    
    // Custom tests
    cr_assert_eq(GetMSB(418302), 18);
    cr_assert_eq(GetMSB(1892374), 20);
    cr_assert_eq(GetMSB(88), 6);
}

Test(ClearBitRange, examples) {
    cr_assert_eq(ClearBitRange(73, 1, 3), 65);
    
    // Custom tests
    cr_assert_eq(ClearBitRange(51234, 3, 8), 51202);
    cr_assert_eq(ClearBitRange(1048575, 5, 12), 1040415);
    cr_assert_eq(ClearBitRange(8493, 10, 2), 8493);
}

Test(RotateLeft, examples) {
    cr_assert_eq(RotateLeft(5, 1), 10);
    cr_assert_eq(RotateLeft(5, 2), 20);
    
    // Custom tests
    cr_assert_eq(RotateLeft(74921, 9), 38359552);
    cr_assert_eq(RotateLeft(2587561053, 14), 3273090702);
    cr_assert_eq(RotateLeft(3333333, 3), 26666664);
}

Test(SwapOddEvenBits, examples) {
    cr_assert_eq(SwapOddEvenBits(23), 43);
    
    // Custom tests
    cr_assert_eq(SwapOddEvenBits(7843210), 12279365);
    cr_assert_eq(SwapOddEvenBits(43219876), 23312216);
    cr_assert_eq(SwapOddEvenBits(2882400001), 1473175298);
}

/* =========================
 * PART 2: IEEE 754 Float
 * ========================= */

Test(ConstructFloat, positive_examples) {
    cr_assert_float_eq(construct_float_sf(0x00, 0x7F, 0x200000), 1.25, 0.00001);
    
    // Custom positive tests
    cr_assert_float_eq(construct_float_sf(0x00, 0x82, 0x400000), 12.0, 0.00001);
    cr_assert_float_eq(construct_float_sf(0x00, 0x85, 0x480000), 100.0, 0.00001);
    cr_assert_float_eq(construct_float_sf(0x00, 0x80, 0x490000), 3.140625, 0.00001);
    cr_assert_float_eq(construct_float_sf(0x00, 0x00, 0x000000), 0.0, 0.00001);
    cr_assert_float_eq(construct_float_sf(0x00, 0x82, 0x080000), 8.5, 0.00001);
    cr_assert_float_eq(construct_float_sf(0x00, 0x7F, 0x000000), 1.0, 0.00001);
}

Test(ConstructFloat, negative_examples) {
    cr_assert_float_eq(construct_float_sf(0x01, 0x7F, 0x200000), -1.25, 0.00001);
    
    // Custom negative tests
    cr_assert_float_eq(construct_float_sf(0x01, 0x82, 0x240000), -10.25, 0.00001);
    cr_assert_float_eq(construct_float_sf(0x01, 0x7C, 0x200000), -0.15625, 0.00001);
    cr_assert_float_eq(construct_float_sf(0x01, 0x84, 0x280000), -42.0, 0.00001);
    cr_assert_float_eq(construct_float_sf(0x01, 0x7E, 0x400000), -0.75, 0.00001);
}

/* =========================
 * PART 3: Integer Conversion
 * ========================= */
/* NOTE:
 * We do NOT test output matching here.
 * Students are encouraged to visually inspect output.
 * TAs will use stronger hidden tests.
 */

Test(ReprConvert, basic_run) {
    repr_convert('2', '2', 0x59f2ca50); 
    repr_convert('S', '2', 0x80000000); 
}

Test(ReprConvert, extended_custom_run) {
    repr_convert('S', '2', 0x8badf00d);
    repr_convert('2', 'S', 0xc0ffee00); 
    repr_convert('S', '2', 0x01234567);
    repr_convert('2', 'S', 0xffffff00); 
    repr_convert('S', '2', 0x800000ff); 
    repr_convert('S', '2', 0xffffffff); 
    repr_convert('2', 'S', 0x7fffffff); 
    repr_convert('2', '2', 0x99887766); 
    repr_convert('S', 'S', 0xf000000f); 
    repr_convert('A', '2', 0x12345678); 
}