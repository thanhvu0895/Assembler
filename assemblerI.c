#include "assembler.h"
/**
 *    Takes opcode (actually funct number in most cases),
 *    pointer to the rest of the statement, and line number for
 *    printing error messages.
 *    Prints I-format instruction to standard output.
 *    
 *    Author: Thanh Vu, Daniel Alspector-Kelly
 *        modified: Febuary 17 completed function
 *        modified: Febuary 19 added tests for invalid/unexpected registers 
 *
 * @param opcode the decimal representation of the operation code
 * @param restOfStmt the rest of the instruction
 * @param line the line number
 */

void assemblerI(int opcode, char *restOfStmt, int line) 
{
    char *parameters[4];
    int numParam = 3;
    //[opcode] [rs] [rt] [rd] [shamt] [func]
    if (opcode == 35 || opcode == 43) 
    {
        //100011,lw, sw
        // Expecting 3 tokens
        // [opcode] opcode.printBin
        // [rs] , [rt] = register, [rd] = NULL
        // last 15 bits = 100??
        if (!getNTokens(restOfStmt, numParam, parameters))
        {
            /* parameters[0] contains error message */
            printError("Unexpected error on line %d: %s\n", line, parameters[0]);
            return;
        }
        //checks if the second parameter is a valid register, if it is, returns with an error
        if (verifyRegName(parameters[1], line, 0) == 1)
        {
            return;
        }
        //checks if the first parameter and third parameters are valid registers, if either of them aren't, returns with an error
        if(verifyRegName(parameters[0], line, 1) == 0 || verifyRegName(parameters[2], line, 1) == 0)
        {
            return;
        }
        printBin(opcode, 6);
        printBin(getRegNbr(parameters[2], line), 5);
        printBin(getRegNbr(parameters[0], line), 5);
        //print offset
        int offset = atoi(parameters[1]);
        printBin(offset, 16);
    }

    else if (opcode == 15) 
    {
        // lui
        //Expecting 2 tokens
        //$rs = 0, $rt = 1 , $ rd = token 2
        //
        numParam = 2;
        if (!getNTokens(restOfStmt, numParam, parameters)) 
        {
            /* parameters[0] contains error message */
            printError("Unexpected error on line %d: %s\n", line, parameters[0]);
            return;
        }
        //checks if the second parameter is a valid register, if it is, returns with an error
        if (verifyRegName(parameters[1], line, 0) == 1)
        {
            return;
        }
        //checks to make sure the first parameter is  a valid register, if it isn't, returns with an error
        if(verifyRegName(parameters[0], line, 1) == 0)
        {              
            return;
        }
        printBin(opcode, 6);
        printf("00000");
        printBin(getRegNbr(parameters[0], line), 5);
        //print address
        int address = atoi(parameters[1]);
        printBin(address, 16);
    }

    else if (opcode == 4 || opcode == 5) 
    {

//        beq, bne I type
// Expecting 3 tokens
//GET RS RT RD
//getRegisters(&rs, &rt, NULL, NULL, &label, tokBegin, tokEnd);
        if (!getNTokens(restOfStmt, numParam, parameters)) 
        {
            /* parameters[0] contains error message */
            printError("Unexpected error on line %d: %s\n", line, parameters[0]);
            return;
        }
        //checks if the third parameter is a valid register, if it is, returns with an error
        if (verifyRegName(parameters[2], line, 0) == 1)
        {
            return;
        }
        int i;
        for(i = 0; i < numParam - 1; i++)
        {
            //checks to make sure the first two parameters are valid registers, if they aren't, returns with an error
            if(verifyRegName(parameters[i], line, 1) == 0)
            {              
                return;
            }
        }
        int address = findLabel(&sTable, parameters[2]);
        //checks if the offset is negative, if it is, returns with an error
        if(((address >> 2) - line) < 0)
        {
            printError("Cannot print binary value of negative decimal value %d on line %d\n", ((address >> 2) - line), line);
            return;
        }
        printBin(opcode, 6);
        printBin(getRegNbr(parameters[0], line), 5);
        printBin(getRegNbr(parameters[1], line), 5);
        //print address / 4 - current line to get offset 
        printBin(((address >> 2) - (line)), 16);
    }
    else if (opcode == 8 || opcode == 9 || opcode == 12 || opcode == 13 || opcode == 10 || opcode == 11) 
    {
        //"addi", "addiu", "andi", "ori", "slti", "sltiu" I type
        // expecting 3 tokens
        // => 2 valid registers and 1 number

        if (!getNTokens(restOfStmt, numParam, parameters)) 
        {
            /* parameters[0] contains error message */
            printError("Unexpected error on line %d: %s\n", line, parameters[0]);
            return;
        }
        //checks if the third parameter is a valid register, if it is, returns with an error
        if (verifyRegName(parameters[2], line, 0) == 1)
        {
            return;
        }
        int i;
        for(i = 0; i < numParam - 1; i++)
        {
            //checks to make sure the first two parameters are valid registers, if they aren't, returns with an error
            if(verifyRegName(parameters[i], line, 1) == 0)
            {              
                return;
            }
        }
        printBin(opcode, 6);
        printBin(getRegNbr(parameters[1], line), 5);
        printBin(getRegNbr(parameters[0], line), 5);
        //print constant value
        int con = atoi(parameters[2]);
        printBin(con, 16);
    }
    printf("\n");
}


