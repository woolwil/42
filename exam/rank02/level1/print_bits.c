#include <unistd.h>

void print_bits(unsigned char octet)
{
    int i = 8;
    unsigned char bit;

    while(i--)
    {
        bit = (octet >> i & 1) + '0';
        write(1, &bit, 1);
    }
}

/*
I'll trace print_bits with octet = 0xB2 (binary 10110010). 
i starts at 8 and while(i--) runs body with i = 7..0.

Before loop: i = 8
Test 1: i-- yields 8 (true), i becomes 7 → body uses i = 7
(octet >> 7) = 00000001 → &1 = 1 → char '1'
Test 2: i-- yields 7, i becomes 6 → body i = 6
(octet >> 6) = 00000010 → &1 = 0 → char '0'
Test 3: i = 5
(octet >> 5) = 00000101 → &1 = 1 → '1'
Test 4: i = 4
(octet >> 4) = 00001011 → &1 = 1 → '1'
Test 5: i = 3
(octet >> 3) = 00010110 → &1 = 0 → '0'
Test 6: i = 2
(octet >> 2) = 00101100 → &1 = 0 → '0'
Test 7: i = 1
(octet >> 1) = 01011001 → &1 = 1 → '1'
Test 8: i = 0
(octet >> 0) = 10110010 → &1 = 0 → '0'
Loop ends when next i-- yields 0.
Printed sequence: "10110010" — the original bit pattern from MSB to LSB.

Note: use parentheses for clarity: (octet >> i) & 1. 
Shifting by 0..7 is safe; shifting by 8 would be undefined behavior.*/