#include "assembler.h"
/**
 *  returns 1 if instr contains valid instruction
 *  digits ('0' and '1'); 0 otherwise
 *  prints error message if instruction is not valid
 *   
 *  Author: Thanh Vu, Daniel Alspector-Kelly
 *
 *      modified: Febuary 17 added documentation, fixed error message
 *
 * @param instr the given instruction
 * @param line the line number
 * @return 1 if instr contains valid instruction name, 0 otherwise
 */

int verifyInstrName(char * instr, int line) {

//opNameArray[] - list of instruction's names
    static char * opNameArray[] =
            {
                    "add", "addu", "sub", "subu", "and", "or", "nor", "sll", "srl", "slt", "sltu", "jr", "addi",
                    "addiu", "andi", "ori", "lw", "sw", "lui", "beq", "bne", "slti", "sltiu", "j", "jal"
            };

        int i;
        for(i=0;i<25;i++)
        {

            if(strcmp(opNameArray[i],instr) == 0)
            {
                return 1;
            }
        }
        printError("Invalid instruction on line %d\n",line);
        return 0;
    }