#include <stdio.h>
#include <math.h>
#include "assembler.h"


/*
 * binToDec
 *
 * This function converts the binary digits from string[begin] to
 * string[end] to a decimal integer.
 *
 * int binToDec(char string[], int begin, int end)
 *   Pre-condition:  begin and end are valid indices in array string;
 *   		     every character from string[begin] to string[end]
 *		     (including those two) has a character value '0' or '1'
 *   Returns: the decimal equivalent of the binary number represented by
 *	      the characters in string[begin] - string[end].
 *            (If begin > end, this function arbitrarily returns 0.)
 *
 * For example, assume A is a character array that contains the
 *    following characters:
 *            '1'  '0'  '1'  '1'  '0'  '1'  '0'  '0'  '1'
 *    The call binToDec(A, 2, 5) converts the binary number 1101
 *    (represented by the substring A[2] - A[5]) to the decimal integer
 *    13 and returns it.
 * 
 * Note: The decimal value returned may appear to be negative if the
 * string being converted is long enough (end - begin + 1 == 32)
 * and if the first character is '1'.
 *
 * Implementation:
 *	The call binToDec(A, 2, 5) should convert the string of binary digits '1' '1' '0' '1' 
 *(the substring A[2] - A[5], inclusive) to the decimal integer 13 and return it.
 *One efficient solution involves building the decimal number from the least significant digit 
 *to the most significant digit by adding in (or not) the appropriate power of two. 
 *Rather than calculating the power of two for each digit, you can store the power of two in a variable 
 *and multiply it by two when you go to the next digit. 
 *(What should the power-of-two variable be initialized to for the least significant digit?)
 *
 *
 * Author:  Thanh
 *	with assistance from: Ronan
 *
 * Creation Date: 01/14/20   
 *	modified: 01/14/20 making changes to the binToDec function so that it works properly.
 *
 */




int binToDec(char string[], int begin, int end) 
{
    int i;
    int decimal = 0;
    int powerCounter = 1;

    if (begin > end) 
    {
        printError("Error trying to look from the 'endIndex' smaller than the 'startIndex':");
        return 0;
    }

    if (begin < 0 || end > 31 || end < 0) 
    {
        printError("Error setting an invalid end or begin:");
        return 0;
    }


    for (i = end; i >= begin; i--) 
    {

        if (string[i] == '1') 
        {
            decimal += powerCounter;
        }

        powerCounter *= 2;
    }
    printDebug("the value is %d\n", decimal);

    return decimal;


}
