#include "assembler.h"

/**
 *    Takes opcode, pointer to the rest of the statement,
 *    and line number for printing error messages.
 *    Prints J-format instruction to standard output.
 * 
 *    Author: Thanh Vu, Daniel Alspector-Kelly
 *
 *        modified: Febuary 17 completed function
 *        modified: Febuary 19 added test for unexpected registers 
 *
 * @param opcode the decimal representation of the operation code
 * @param restOfStmt the rest of the instruction
 * @param line the line number
 */

void assemblerJ(int opcode, char *restOfStmt, int line)
 {
    char *parameters[4];
    int numParam = 1;
    if (opcode == 2 ||opcode == 3)
    {

        if (!getNTokens(restOfStmt, numParam, parameters))
        {
            /* parameters[0] contains error message */
            printError("Unexpected error on line %d: %s\n", line, parameters[0]);
            return;
        }
        //checks if the first parameter is a valid register, if it is, returns with an error
        if (verifyRegName(parameters[0], line, 0) == 1)
        {
            return;
        }
        printBin(opcode, 6);
        int address = findLabel(&sTable, parameters[0]);
        //print address / 4
        printBin(address >> 2, 26);

    }
        //j and jal
        //getRegisters(2/3, NULL, NULL, NULL, &label
    printf("\n");
}


