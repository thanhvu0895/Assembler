#include "assembler.h"

/**
 * Takes register name (e.g., $t0) and returns register number.
 * Takes line number as input for printing error messages.
 * 
 *  Author: Thanh Vu, Daniel Alspector-Kelly
 *
 *      modified: Febuary 22 added documentation
 *
 * @param regName - a char that represents the register name
 * @param line - an int that represents the line number to print out error messages
 * @return an int that corresponds to the given register
 */

int getRegNbr(char *regName, int line) 
{

    static char *regArray[] =
            {
                    "$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5",
                    "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1",
                    "$gp", "$sp", "$fp", "$ra"
            };


    int i;
    for ( i = 0; i < 32; i++) {
        //if it is a valid register
        if (strcmp(regName, regArray[i]) == SAME) 
        {
            return i;
        }
    }
    //if it isn't a valid register
    printError("Invalid reg %s name on line %d\n", regName, line);
    return -1;
}

