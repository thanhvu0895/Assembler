#include "assembler.h"

/**
 *    Takes opcode (actually funct number in most cases),
 *    pointer to the rest of the statement, and line number for
 *    printing error messages.
 *    Prints R-format instruction to standard output.
 *    Author: Thanh Vu, Daniel Alspector-Kelly
 *
 *        modified: Febuary 17 completed function
 *        modified: Febuary 19  added tests for invalid/unexpected registers 
 *
 * @param opcode the decimal representation of the operation code
 * @param restOfStmt the rest of the instruction
 * @param line the line number
 */

void assemblerR(int opcode, char *restOfStmt, int line)
{
//i < 12 -> [opcode] [rs] [rt] [rd] [shamt] [func]
// with [opcode] = 000000

    char *parameters[4];
    int numParam = 3;

    if (opcode == 0 || opcode == 2) 
    {
        // 000000, 000010
        // "sll", "srl"
        // Expecting 3 tokens.
        // opcode = 0.printBin
        // shamt = 10.printBin
        // func/opcode = code.printBin
        // rs rt rd -> getRegNbr also check if they are valid
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
        printf("000000");
        printf("00000");
        printBin(getRegNbr(parameters[1], line), 5);
        printBin(getRegNbr(parameters[0], line), 5);
        int shamt = atoi(parameters[2]);
        //print shift amount
        printBin(shamt, 5);
        printBin(opcode, 6);


    }
    else if (opcode == 8) 
    {
        // CASE 2: 001000 => jr
        // Expecting 1 token.
        // if (strcmp(rs, "$ra") != SAME) {
        //                (void) fprintDebug(stderr, "The jr command must be followed by the $ra register \n");
        //            }
        // ($ra).getRegNbr().printBin()
        // rt = "$zero"; rd = "$zero";
        // shamt = 0


        numParam = 1;
        if (!getNTokens(restOfStmt, numParam, parameters)) 
        {
            /* parameters[0] contains error message */
            printError("Unexpected error on line %d: %s\n", line, parameters[0]);
            return;
        } 
        if (getRegNbr(parameters[0], line) != 31) 
        {
            printError("Invalid reg %s on line %d\n", parameters[0], line);
            return;
        } 
        printf("000000");
        //print 31 = $ra
        printBin(getRegNbr(parameters[0], line), 5);
        printf("00000");
        printf("00000");
        printf("00000");
        printBin(opcode, 6);
    }


    else if ((opcode > 31 && opcode < 38) || opcode == 39 || opcode == 42 || opcode == 43)
    {

//opcode == 32, 33, 34, 35, 36, 37, 39, 42, 43
//[opcode] [rs] [rt] [rd] [shamt] [func]
//100000, 100001, 100010, 100011, 100100, 100101, 100111, 101010, 101011
// "add", "addu", "sub", "subu", "and", "or", "nor",  "slt","sltu",
// shamt = "0";
// rs rt rd. get => printBin
// string [opcode] = 000000
//  func = code.printBin
        numParam = 3;
 
        printDebug("Line %d \n\tExpect 3 tokens\n\tActual: %s ", line, restOfStmt);

        if (!getNTokens(restOfStmt,numParam, parameters)) 
        {
            /* parameters[0] contains error message */
            printError("Unexpected error on line %d: %s\n", line, parameters[0]);
            return;
        } 
        int i;
        for(i = 0; i < numParam; i++)
        {
            //checks to make sure the three parameters are valid registers, if they aren't, returns with an error
            if(verifyRegName(parameters[i], line, 1) == 0)
            {                          
                return;
            }
        }
        printf("000000");
        printBin(getRegNbr(parameters[1], line),5);

        printBin(getRegNbr(parameters[2], line),5);

        printBin(getRegNbr(parameters[0], line), 5);
        printf("00000");
        printBin(opcode,6);
    }
    printf("\n");
}


