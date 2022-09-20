#include "assembler.h"
#include <math.h>
#include <stdio.h>

/**
 * Takes a numeric value and prints the binary format to
standard output as characters.  The length specifies how
many binary digits to print.
Cannot print negative values and will print an error and return if given 
negative decimal input.
E.g., printBin (3, 5) would print 00011 to stdout (the binary
representation for the number 3, evaluepressed using 5 characters).

 *    Author: Thanh Vu, Daniel Alspector-Kelly
 *
 *        modified: Febuary 17 added documentation
 * 
 * @param value an int that represents a decimal value
 * @param length - an int that specifies the number of digits we are printing.
 */

void printBin(int value, int length) 
{
    if(value < 0)
    {
        printError("Cannot print binary value of negative decimal value %d\n", value);
        return;
    }
    int i;

    for (i = length -1 ; i >= 0; i--) 
    {
        // iterate from bit_number_4 to bit_number_0,
        // bit 4 must be printed first as we are reading from left to right

        // shift bits so bit number i becomes bit number 0
        int bit_i_unmasked = value >> i;
        //eg 32 -> shift 5 = 00032

        // set other bits to 0 by using bitwise AND operator
        //The & (bitwise AND) in C or C++ takes two numbers
        // as operands and does AND on every bit of two numbers.
        // The result of AND is 1 only if both bits are 1.
        int bit_i = bit_i_unmasked & 1;
        // now bit_i has value 0 or 100100


        // convert bit_i to a character, '0' or '1',
        // calculation below is either ('0' + 0) or ('0' + 1)
        char binary_digit = '0' + bit_i;
        // bit '0' + 1

        // print the digit character
        putchar(binary_digit);

    }
}





