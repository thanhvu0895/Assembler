#include "assembler.h"
/**
 *  returns 1 if instr contains valid instruction
 *  digits ('0' and '1'); 0 otherwise
 *  prints an appropriate error based on the expected result
 *   
 *  Author: Thanh Vu, Daniel Alspector-Kelly
 *
 *      modified: Febuary 17 added documentation, fixed error message
 *      modified: Febuary 21 added parameter to specify the expected result for proper error printing
 *
 * @param instr the given instruction
 * @param line the line number
 * @param expected boolean integer for whether the expected result is 1(valid) or 0(invalid)
 * @return 1 if reg contains valid register name, 0 otherwise
 */

int verifyRegName(char * reg, int line, int expected) {

//regArray[] - list of register names
  static char *regArray[] =
            {
                    "$zero", "$at", "$v0", "$v1", "$a0", "$a1", "$a2", "$a3", "$t0", "$t1", "$t2", "$t3", "$t4", "$t5",
                    "$t6", "$t7", "$s0", "$s1", "$s2", "$s3", "$s4", "$s5", "$s6", "$s7", "$t8", "$t9", "$k0", "$k1",
                    "$gp", "$sp", "$fp", "$ra"
            };

        int i;
        for(i=0;i<32;i++)
        {
            //if it is a valid register
            if(strcmp(regArray[i], reg) == SAME)
            {
                //if the expected result is 0(invalid)
                if(expected == 0)
                {
                    printError("Unexpected register %s on line %d\n", reg, line);
                }
                return 1;
            }
        }      
        //if it isn't a valid register
        //if the expected result is 1(valid)
        if(expected == 1)
        {
            printError("Invalid reg %s on line %d\n", reg, line);
        }
        return 0;
    }