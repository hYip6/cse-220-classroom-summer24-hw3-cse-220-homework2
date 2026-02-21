HW3/
├── Makefile
├── HW3_main.c
├── MyBitManipulation.h
├── MyBitManipulation.c
├── Myfloat.h
├── Myfloat.c
├── MyIntegers.h
├── MyIntegers.c
└── README.txt  


1- write your name and SBU ID in each of the file.

PART 1: BIt Manipulation
I used a mix of very large numbers (like 2882400001) and small numbers 
(like 88) to verify that my bitwise operations target the exact correct 
positions. These cases ensure that the logic holds up across the entire 
32-bit range without accidentally losing bits during shifts or rotations 
near the boundaries.

PART 2: IEEE 754 Float Construction
These tests verify that the raw bits for the sign, exponent, and fraction 
are successfully packed into the correct 32-bit layout. I tested:
* Normal Positives/Negatives: To ensure the sign bit toggles correctly.
* Whole Numbers/Fractions: To ensure the exponent and mantissa align 
  perfectly with expected decimal values.
* Zero (0.0): A specific edge case where all 32 bits must be zero.

PART 3: Integer Representation
These cases verify the boundaries of converting between Two's Complement 
('2') and Sign-Magnitude ('S'). 
* Positives: Ensures positive numbers remain unchanged, as they are 
  identical in both formats.
* Negatives: Uses random negative values to guarantee bits flip correctly 
  when swapping formats.
* Boundaries: Tests the maximum possible positive and negative values 
  to ensure the logic doesn't overflow.
* Errors: Includes invalid input flags (like 'A') to confirm the program 
  handles bad inputs.

Bit Manipulation:
- GetMSB(418302) -> Expected: 18
- GetMSB(1892374) -> Expected: 20
- GetMSB(88) -> Expected: 6
- ClearBitRange(51234, 3, 8) -> Expected: 51202
- RotateLeft(74921, 9) -> Expected: 38359552
- SwapOddEvenBits(7843210) -> Expected: 12279365

Float Construction (Sign, Exp, Frac):
- (0x00, 0x82, 0x400000) -> Expected: 12.0
- (0x01, 0x82, 0x240000) -> Expected: -10.25
- (0x00, 0x80, 0x490000) -> Expected: 3.140625
- (0x00, 0x00, 0x000000) -> Expected: 0.0

Integer Conversion (Source, Target, Value):
- ('S', '2', 0x8badf00d) -> Expected: f4520ff3
- ('2', 'S', 0xc0ffee00) -> Expected: bf001200
- ('S', '2', 0x800000ff) -> Expected: ffffff01
- ('A', '2', 0x12345678) -> Expected: error