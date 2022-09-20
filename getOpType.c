/**
*
* Takes opcode (mnemonic name, e.g., "add") and returns
*   opType ('R', 'I', 'J') and code (opcode or funct number).
*
* Description: Takes line number as input for printing error messages.
*
* @Parameter: *opcode - pointer to string containing mnemonic name such as add
*            *opType - pointer to string containing opType ('R', 'I', 'J')
*            code - a char that represents the corresponding func or opcode to the mnemonic name such as add
*            line - an int that represents the line number of given mnemonic name such as add.
*
*
*
* @return: does not return anything.
*
*
* Author: Daniel Alspector-Kelly, Thanh Vu
* Date:   February 15 2020
*
* Modified by:
*             Thanh - to complete the function
*
*
*/
#include "assembler.h"
#include <string.h>
#include <math.h>


void getOpType(char *opcode, char *opType, int *code, int line) 
{

    //opNameArray[] - list of instruction's names
    static char *opNameArray[] =
            {
                    "add", "addu", "sub", "subu", "and", "or", "nor", "sll", "srl", "slt", "sltu", "jr", "addi",
                    "addiu", "andi", "ori", "lw", "sw", "lui", "beq", "bne", "slti", "sltiu", "j", "jal"
            };

    // opArray[] - list of corresponding opcode to the instruction name.
    static char *codeArray[] =
            {
                    "100000", "100001", "100010", "100011", "100100", "100101", "100111", "000000", "000010", "101010",
                    "101011", "001000", "001000", "001001", "001100", "001101", "100011", "101011", "001111", "000100",
                    "000101", "001010", "001011", "000010", "000011"
            };


    // formatArray[] - list of corresponding format to the instruction name
    static char *formatArray[] =
            {
                    "R", "R", "R", "R", "R", "R", "R", "R", "R", "R", "R", "R", "I", "I", "I", "I", "I", "I", "I", "I",
                    "I", "I", "I", "J", "J"
            };


    // Go through each valid instruction and set code, format and line number

    printDebug("\n\n=============BEFORE CALLING GET OPTYPE ============\n");
    printDebug("The instruction name is %s \n", opcode);
    printDebug("codeArray[0] test Bin to Dec: %d \n", binToDec(codeArray[1], 0, 5));


    int a = strcmp(opcode, opNameArray[0]);

    int i;
    int OPNUM = 25;

    for (i = 0; i < OPNUM; i++) 
    {

        if (strcmp(opcode, opNameArray[i]) == SAME) 
        {
            *opType = *formatArray[i];
            *code = binToDec(codeArray[i], 0, 5);
        }
    }
}
















